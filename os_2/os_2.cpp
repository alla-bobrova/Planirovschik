#include <iostream> 
#include<conio.h> 
#include<stdio.h> 
#include<locale.h> 
#include<stdlib.h> 
#define QUEUE struct QUEUE 
 
QUEUE{ int ID; 
int timeCPU; //время процесса 
}; 
 
void gant(QUEUE* process, int N) //график ганта 
{ 
float Wtime = 0, Atime = 0, Itime = 0; 
float Stime = 0; 
 
for (int i = 0; i < N; i++) //сумма времени 
Stime = Stime + proces[i].timeCPU; 
 
printf_s(" ||"); 
 
for (int i = 1; i <= Stime; i++) 
printf_s("%3d", i); 
printf_s("\n"); 
 
for (int i = 1; i <= Stime + 2; i++) 
printf_s("___"); 
printf_s("\n"); 
 
for (int i = 0; i < N; i++) 
{ 
for (int a = 0; a < N; a++) 
if (process[a].ID == i + 1) 
{ 
printf_s("%3d| ", i + 1); 
 
for (int j = 0; j < a; j++) 
for (int k = 0; k < process[j].timeCPU; k++) 
{ 
printf_s("г "); //процесс готов к исполнению 
Wtime++; //общее время ожидания 
} 
 
for (int k = 0; k < process[a].timeCPU; k++) 
{ 
printf_s("и "); //процесс исполняется 
Itime++; //общее время исполнения 
} 
printf_s("\n"); 
} 
} 
 
for (int i = 1; i <= Stime + 2; i++) 
printf_s("___"); 
printf_s("\n"); 
 
printf("\nВремя, необходимое для обработки всех процессов = %0.2f\n", Stime); 
printf("\nСреднее время выполнения = %0.2f\n", (Wtime + Itime) / N); 
printf("\nСреднее время ожидания = %0.2f\n\n", Wtime / N); 
} 
 
int main() 
{ 
setlocale(LC_ALL, "RUS"); 
int alg = 0; 
int N; //количество процессов 
int tmp = 0; 
QUEUE* process; 
 
printf_s("Количество процессов = "); 
scanf_s("%d", &N); 
process = new QUEUE[N]; 
printf_s("\n"); 
 
for (int i = 1; i <= N; i++) 
{ 
(process + i - 1)->ID = i; 
printf_s(" *Время исполнения процесса %d = ", i); //запрашиваем время 
scanf_s("%d", &(process + i - 1)->timeCPU); 
printf_s("\n"); 
} 
 
while (1) //выбор алгоритма 
{ 
printf_s("Алгоритм: 1) FCFS 2) SJF \n"); 
scanf_s("%d", &alg); 
if (alg < 0 || alg>2) //ошибка 
{ 
printf("\nВыберите 1 или 2.\n"); 
continue; 
} 
else //если ввели 1 или 2 
break; 
} 
if (alg == 1) //если выбрали FCFS 
{ 
gant(process, N); 
} 
 
else //если выбрали SJF 
{ 
for (int i = 0; i < N; i++) 
for (int j = N - 1; j > i; j--) 
if ((process + j)->timeCPU < (process + j - 1)->timeCPU) 
{ 
tmp = (process + j)->ID; 
(process + j)->ID = (process + j - 1)->ID; 
(process + j - 1)->ID = tmp; 
 
tmp = (process + j)->timeCPU; 
(process + j)->timeCPU = (process + j - 1)->timeCPU; 
(process + j - 1)->timeCPU = tmp; 
} 
gant(process, N); //график 
} 
}


