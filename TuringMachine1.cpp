#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define STR_LENGTH 100
#define LIMIT 5

using namespace std;


void print_head();
void print_message();
void print_line();
void update_string(char, char);

char string1[STR_LENGTH];
int head, string_length;

int main()
{
    int limit, i, flag;
    char current_state[MAX_LENGTH][LIMIT], new_state[MAX_LENGTH][LIMIT];
    char input_symbol[MAX_LENGTH], write_symbol[MAX_LENGTH], move_on[MAX_LENGTH];
    char state[LIMIT];
    print_message();
    for(limit = 0 ; limit < MAX_LENGTH ; limit++)
    {

        cin>>current_state[limit];
        if(!strcmp(current_state[limit], "$"))
        {
            break;
        }
        cin>>input_symbol[limit]>>write_symbol[limit]>>move_on[limit]>>new_state[limit];
    }
    cout<<endl;
    printf("输入字符串 : ");
    scanf("%s", string1);
    string_length = strlen(string1);
    printf("\n");

  head = 0;
  strcpy(state, current_state[0]);
  while(1)
  {
    flag = 0;
    for(i = 0 ; i < limit ; i++)
    {
      if(!strcmp(state, current_state[i]) && string1[head] == input_symbol[i])
      {
        update_string(write_symbol[i], move_on[i]);
        strcpy(state, new_state[i]);
        printf("%-10s\t|  state = %s\n", string1, new_state[i]);
        if(!strcmp(state, "#"))
          flag = 2;
        else
          flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      printf("拒绝的!\n");
      printf("没有输入符号的生成 \'%c\' 在状态 \'%s\'.\n图灵机停机\n", string1[head], state);
      break;
    }
    else if(flag == 2)
    {
      printf("认可的!图灵机停机!\n");
      break;
    }
  }
    printf("\n");

    system("pause");
    return 0;
}

void update_string(char symbol, char move_step)
{
  int i;
  string1[head] = symbol;
  if(move_step == 'r')
    head++;
  else if(move_step == 'l')
    head--;
  if(head == -1)
  {
    for(i = string_length ; i > 0 ; i--)
      string1[i] = string1[i - 1];
    string1[0] = '_';
    string_length++;
    string1[string_length] = '\0';
    head = 0;
  }
  else if(head == string_length)
  {
    string1[string_length] = '_';
    string_length++;
    string1[string_length] = '\0';
  }
}


void print_message()
{
  printf("进入图灵机输入代码\n");
  printf("输入格式:\n");
  printf("<当前状态> <读入的字符> <写入的字符> <移动方向> <新的状态>\n");
  printf("移动方向 用 r 表示向右移动，用 l 表示向左移动.\n");
  printf("单个转换应用占一行.\n");
  printf("输入符号，新符号和移动是单个字符.\n");
  printf("当前状态和新状态可以是5个字符范围内的任何字符组合.\n");
  printf("第一个当前状态将被视为您的初始状态\n");
  printf("使用 \'_\' 作为拒绝状态, \'#\' 作为接受状态\n");
}



