#define  gear1    10           //定义舵机1引脚
#define  gear2    11           //舵机2引脚
#define  gear3    12           //舵机3引脚
#define  gear4    13           //舵机4引脚   
#define  average    5000           //  5000us    20000us内控制完4个舵机，每个舵机分为5000us
 
int flag = 1;              //舵机启动/停止
 
int start = 0;
int pwm[4] = {1500,1500,1500,1500};                 // 范围在500~2400us
void servo_run(int k,int l,int m, int n);           //范围在500~2400us 
void initTime1();
void timer1(int value);
 
 
void setup()
{
  Serial.begin(9600);
  pinMode(gear1, OUTPUT);
  pinMode(gear2, OUTPUT);
  pinMode(gear3, OUTPUT);
  pinMode(gear4, OUTPUT);
 
}
 
void loop()
{ 
  servo_run(1000,0,0,0);        //第一组动作
  delay(2000);                  //等待动作执行完毕
  servo_run(2000,0,0,0);        //第二组动作
  delay(2000);
//  while(1);                //停止在第二组动作
////  flag = 0;             //停止舵机
}
void initTime1()
{ 
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B = 0x0D;            //1024分频
  TIMSK1 |= (1 << TOIE1);  
 }
void timer1(int value)
{
   TCNT1 = 0xffff - value * 16 / 1024;
}
 
ISR(TIMER1_OVF_vect)
{
  static  int i = 1;
  if (flag) {
    switch (i)
    {
      case 1 :                                            //控制舵机1
        {
          digitalWrite(gear1, HIGH);
          timer1(pwm[0]);
        } break;
      case 2 :
        {
          digitalWrite(gear1, LOW);
          timer1(average - pwm[0]);
        } break;
 
      case 3 :                                            //控制舵机2
        {
          digitalWrite(gear2, HIGH);
          timer1(pwm[1]);
        } break;
      case 4 :
        {
          digitalWrite(gear2, LOW);
          timer1(average - pwm[1]);
        } break;
 
      case 5 :                                            //控制舵机3
        {
          digitalWrite(gear3, HIGH);
          timer1(pwm[2]);
        } break;
      case 6 :
        {
          digitalWrite(gear3, LOW);
          timer1(average - pwm[2]);
        } break;
 
      case 7 :                                            //控制舵机4
        {
          digitalWrite(gear4, HIGH);
          timer1(pwm[3]);
        } break;
      case 8 :
        {
          digitalWrite(gear4, LOW);
          timer1(average - pwm[3]);
        } break;
      case 9:
        {
          i = 0;
          timer1(1000);                     //1000us后进入case1
        }
      default: break;
    }
    i++;
   }
}
 
void servo_run(int k,int l,int m, int n)
{
        pwm[0] = k;  
        pwm[1] = l;
        pwm[2] = m;  
        pwm[3] = n;    
        initTime1();
        timer1(1000);               //给一个脉冲，进入中断
 }
 
