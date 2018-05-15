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
    printf("�����ַ��� : ");
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
      printf("�ܾ���!\n");
      printf("û��������ŵ����� \'%c\' ��״̬ \'%s\'.\nͼ���ͣ��\n", string1[head], state);
      break;
    }
    else if(flag == 2)
    {
      printf("�Ͽɵ�!ͼ���ͣ��!\n");
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
  printf("����ͼ����������\n");
  printf("�����ʽ:\n");
  printf("<��ǰ״̬> <������ַ�> <д����ַ�> <�ƶ�����> <�µ�״̬>\n");
  printf("�ƶ����� �� r ��ʾ�����ƶ����� l ��ʾ�����ƶ�.\n");
  printf("����ת��Ӧ��ռһ��.\n");
  printf("������ţ��·��ź��ƶ��ǵ����ַ�.\n");
  printf("��ǰ״̬����״̬������5���ַ���Χ�ڵ��κ��ַ����.\n");
  printf("��һ����ǰ״̬������Ϊ���ĳ�ʼ״̬\n");
  printf("ʹ�� \'_\' ��Ϊ�ܾ�״̬, \'#\' ��Ϊ����״̬\n");
}



