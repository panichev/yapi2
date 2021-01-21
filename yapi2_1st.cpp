#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "string.h"
#include "time.h"

int show(int* a, int n, int* numbers, int letid) {
    /* static int num=1;
     printf("%d: ",num);
     num++;
     if(num==1441262){
         int j=0;
     }
     if(a[0]==7 && a[1]==9 && a[2]==2 && a[3]==5 && a[4]==0 && a[5]==4 && a[6]==8 && a[7]==1 && a[8]==3 && a[9]==6){
         int j=0;
     }
     */
    for (int i = 0, j = 0; i < n; i++) {
        // printf("%d", a[i]);
        if (j <= letid) {
            numbers[i] = a[i];
            j++;
        }
    }
    //  printf("\n");

    return 1;
}

void swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}
int NextSet(int* a, int n)
{
        int j = n - 2;
        while (j != -1 && a[j] >= a[j + 1]) j--;
        if (j == -1)
            return 0; // больше перестановок нет
        int k = n - 1;
        while (a[j] >= a[k]) k--;
        swap(a, j, k);
        int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
        while (l < r)
            swap(a, l++, r--);

    
    return 1;
}
int main() {
    printf("Hello, World!\n");
    printf("Input expression:\n");
    char words[9][9];
    char letters[11];
    int numbers[10];
    int rezmas[10];
    int rezmas2[10];
    int upper[9];
    char sym = 5;
    int i = 0;
    int j = 0;
    int letId = 0;
    float start_time;
    while (1) {
        scanf("%c", &sym);
        if (sym == '+' || sym == '=') {
            words[i][j] = '\0';
            j = 0;
            i++;
            scanf("%c", &sym);
        }
        else if (sym == '\n') {
            words[i][j] = '\0';
            break;
        }
        // связываем буквы с цифрами
        start_time = clock();
        while (1) {
            int k = 0;
            for (k; k < 9; k++) {
                if (letters[k] == sym) {
                    break;
                }
            }
            if (letters[k] == sym) break;
            if (k == 9) {
                letters[letId] = sym;
                letId++;
                break;

            }
            else {

                break;
            }
        }
        words[i][j] = sym;
        j++;
    }
    letId--;
    for (int k = 0; k <= i; k++) {
        printf("%s\n", words[k]);
    }
    //считаем кол-во букв в ответе
    unsigned int sizeAns = strlen(words[i]);
    int sizeAns2 = sizeAns - 1;
    unsigned int max;
    //начинвем перебирать
    i--;
    int n = 10;
    int a[11];
    a[0] = 1; a[1] = 0; a[2] = 2; a[3] = 3; a[4] = 4; a[5] = 5; a[6] = 6; a[7] = 7; a[8] = 8; a[9] = 9;
    show(a, n, numbers, letId);
    
        int noSwap;
        for (int k = i; k >= 0; k--)
        {
            noSwap = 1;
            for (int k1 = 0; k1 < k; k1++) {
                char temp[10];
                int i1 = strlen(words[k1 + 1]);
                int i2 = strlen(words[k1]);
                if (i2 > i1) {
                    strcpy(temp, words[k1 + 1]);
                    strcpy(words[k1 + 1], words[k1]);
                    strcpy(words[k1], temp);
                }
            }
        }
    
            unsigned int cntLetters[8];
        //считаем количество букв в словах до "="
        for (int k = i; k >= 0; k--) {
            cntLetters[k] = strlen(words[k]) - 1;
            if (k == i) {
                max = cntLetters[k];
            }
            if (i - k >= 2) {
                if (cntLetters[k] > cntLetters[k + 1]) {
                    max = cntLetters[k];
                }
            }
        }
    
    int scht = 0;
    while (NextSet(a, n)) {
        int ans1 = 0;
        int ans2 = 0;
        memset(upper, 0, sizeof(upper));
        scht++;
        show(a, n, numbers, letId);

        int sum = 0;
        upper[sizeAns] = 0;
        short flag = 0;
        sizeAns = strlen(words[i + 1]) - 1;

        char words2[10][10];


        for (int cnt2 = cntLetters[i]; cnt2 >= 0; cnt2--) {

            for (int cnt = i; cnt >= 0; cnt--) {

                int qrt = max - cntLetters[cnt];


                if (cnt2 - qrt < 0) {
                    break;
                }

                for (int cnt3 = 0; cnt3 <= letId; cnt3++) {

                    if (words[cnt][cnt2 - qrt] == letters[cnt3]) {
                        if ((cnt2 - qrt == 0) && (numbers[cnt3] == 0)) {
                            sizeAns = strlen(words[i + 1]) - 1;

                            flag = 1;
                            break;
                        }
                        sum += numbers[cnt3];
                        break;
                    }
                }


                //}
                if (flag == 1) {
                    break;
                }

            }
            if (flag == 1) {
                break;
            }
            i++;
            for (int k = 0; k <= sizeAns; k++) {
                for (int k2 = 0; k <= letId; k2++) {
                    if (words[i][k] == letters[k2]) {
                        rezmas2[k] = numbers[k2];
                        break;
                    }
                }
            }
            i--;
            if (rezmas2[0] == 0) {
                goto next;
            }
            if (sum < 10) {
                if (upper[sizeAns] > 0) {

                    if (sum + upper[sizeAns] >= 10) {
                        //sizeAns--;
                        goto check;
                    }
                    else {
                        sum += upper[sizeAns];
                    }
                }
                rezmas[sizeAns] = sum;

                sizeAns--;

                // if(sizeAns==0)
            }
            else {
            check:
                if (upper[sizeAns] > 0) {
                    rezmas[sizeAns] = (sum + upper[sizeAns]) % 10;
                    sum += upper[sizeAns];
                }
                else {
                    rezmas[sizeAns] = sum % 10;
                }
                if (sizeAns == 0 && max == sizeAns2) {
                    rezmas[0] = 1;
                }
                else {
                    sizeAns--;
                    //убрать участок

                    upper[sizeAns] += sum / 10;
                    if (sizeAns == 0) {
                        rezmas[0] = upper[0];
                    }
                }
            }



            sum = 0;
        }
        if (flag == 1) {
            goto next;
        }
        sum = 0;
        if (rezmas[0] < 10) {
            int jq = 9;
        }
        sizeAns = strlen(words[i + 1]) - 1;
        sizeAns2 = sizeAns;
        rezmas[sizeAns + 1] = '\0';
        
        for (int k = 0; k <= sizeAns; k++) {
            int t;
            int t1;
            int q1 = sizeAns - k;
            int q2 = sizeAns - k;
            if (q1 < 0 || q2 < 0) {
                break;
            }
            if (rezmas[0] != 0) {
                int abc = 10;
            }
            t = rezmas[k];
            t1 = rezmas2[k];
            for (q1; q1 > 0; q1--) {
                t *= 10;
                t1 *= 10;
            }
            ans1 += t;
            ans2 += t1;
        }
        if (ans1 == ans2) {
            float end_time = clock();
            printf("Ответ найден: \nans1=%d\nans2=%d", ans1, ans2);
            printf("\ntime = %.4f sec", (end_time - start_time) / CLOCKS_PER_SEC);
            scanf("%d", &i);
            return 0;
        }
        if (sum - 1 == sizeAns) {
            return 0;
        }


    next:

        for (int k = 0; k <= letId; k++) {
            rezmas[k] = 0;
            rezmas2[k] = 0;
        }


    }


    return 1;
}
