#include <stdio.h>
#include <string.h>

typedef char String[11];
int health, hygiene, happiness, social, money, turn, choice, maxTurn;
String x;

int checkValue(int num){
  int ans;
  if (num>100)
    ans=100;
  else if (num<0)
    ans=0;
  else
    ans=num;
  return ans;
}

int main()
{
  //Info user Profil
  String nickname;
  int health=100;
  int hygiene=100;
  int happiness=50;
  int social=50;
  int money=10;
  int turn=0;
  int maxTurn=2;//JANGAN LUPA DIGANTI 50

  //Nickname
  printf("Masukkan nickname: ");
  scanf("%s", &nickname);

  printf("RULES\n");
  printf("1. Pemain menang ketika social dan happiness mencapai 100. \n2. Pemain dapat melakukan berbagai aksi untuk menaikkan atau menurunkan stats. \n3. Health -2 tiap turn, saat hygiene<50, dan saat happiness<50. \n4. Happiness -2 saat social<50, hygiene<50, dan money<10. \n5. Social -2 ketika hygiene<50.\n6. Money +1 tiap turn. \n6. Jika money<0 selama 5 turn, pemain akan bangkrut. \n7. Jika health=0, turn mencapai 50, atau pemain bangkrut, pemain kalah.\n");
  printf("Ketik apapun untuk melanjutkan \n");
  scanf("%s", x);

  //Loop utama
  while (turn<maxTurn)
  {
    //Menampilkan info profil
    printf("Nickname = %s\n", nickname);
    printf("-----------------\n");
    printf("|Health\t  = %d\t| \n|Hygiene  = %d\t| \n|Happiness= %d\t| \n|Social\t  = %d\t| \n|Money\t  = %d\t| \n|Turn\t  = %d\t| \n", health,hygiene,happiness,social,money,turn+1);
    printf("-----------------\n\n");

    //Syarat Kalah
    if (health==0)
    {
      printf("Game Over! Mati!\n");
      break;
    }
    if (money<0)
    {
      bankrupt++;
    }
    if (money>=0)
    {
      bankrupt=0;
    }
    if (bankrupt==5)
    {
      printf("Game Over! Bangkrut!\n");
      break;
    }

    //Syarat Menang
    else if (social=100 && happiness==100)
    {
      printf("You Win!");
      break;
    }

    //Game
    else
    {
      //Kegiatan Robot
      printf("-----------------\n");
      printf("|Aktivitas: \t| \n|1.Kerja lembur |(+10 Money, -5 Hygiene, -3 Happiness) \n|2.Kerja \t|(+5 Money, -2 Hygiene, -1 Happiness) \n|3.Repair+ \t|(+0 Health, +0 Hygiene, +0 Happiness, -0 Money) \n|4.Repair \t|(+0 Health, +0 Hygiene, -0 Money) \n|5.Bakti sosial |(+0 Social, +0 Happiness, -0 Hygiene, -0 Money) \n|6.Bermain \t|(+0 Happiness, -0 Hygiene, -0 Social, -0 Money) \n|7.Nongkrong \t|(+0 Social, +0 Happiness, -0 Hygiene, -0 Money) \n|8.Mandi \t|(+3 Hygiene, -2 Money) \n");
      printf("-----------------\n\n");

      printf("Pilihan Aktivitas (input angka saja!) : \n");
      scanf("%d", &choice);

      switch(choice)
      {
        case 1 :
          money +=10;
          hygiene -=5;
          happiness -=3;
        break;
        case 2 :
          money +=5;
          hygiene -=2;
          happiness -=1;
        break;
        case 3 :
          health +=0;
          hygiene +=0;
          happiness +=0;
          money -=0;
        break;
        case 4 :
          health +=0;
          hygiene +=0;
          money -=0;
        break;
        case 5 :
          social +=0;
          happiness +=0;
          hygiene -=0;
          money -=0;
        break;
        case 6 :
          happiness +=0;
          social -=0;
          hygiene -=0;
          money -=0;
        break;
        case 7 :
          social +=0;
          happiness +=0;
          hygiene -=0;
          money -=0;
        break;
        case 8 :
          hygiene +=3;
          money -=2;
        break;
        default:
          printf("Input salah!\n");
      }
      //Turn
      money +=1;
      if (hygiene<50 || happiness<50)
      {
        health =checkValue(health-2);
      }
      hygiene =checkValue(hygiene-2);
      if (social<50 || hygiene<50 || money<10)
      {
        happiness=checkValue(happiness-2);
      }
      if (hygiene<50)
      {
        social =checkValue(social-2);
      }
      turn++;
    }
  }
    if (turn==maxTurn)
    {
      printf("Game Over! Turn habis!\n");
    }
    
    if (social=100 && happiness==100)
    {
      printf("You Win!");
      break;
    }
}