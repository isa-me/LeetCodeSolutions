#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char * s){
    int sSize = strlen(s)+1;
    printf("Before funtion call:\nString = %s\nArray Length(including null) = %d\n\n",s,sSize);
    int pSize = 0;
    int offset = 0;
    for(int i = 0; i<sSize; i++){
        if((s[i]>=65)&&(s[i]<=90)){
            s[i-offset] = s[i]+32;
            pSize++;
        }
        else if((s[i]>=97)&&(s[i]<=122)){
            s[i-offset] = s[i];
            pSize++;
        }
        else if((s[i]>=48)&&(s[i]<=57)){
            s[i-offset] = s[i];
            pSize++;
        }
        else offset++;

        //printf("%d) %s, pSize = %d\n",i+1,s,pSize);
    }
    s[pSize] = 0;
    //printf("\n\n");
    //pSize = strlen(s)+1;
    //printf("End of funtion call:\nString = %s\nArray Length(including null) = %d\n\n",s,pSize);
    int middle, last;
    middle = ((pSize)/2);
    last = pSize-1;
    char tmp;
    for(int i = 0; i<middle;i++){
        if(s[i] != s[last]) return false;
        last--;
    }
    return true;
}
int main(){
    int n = strlen("A man, a plan, a canal: Panama")+1;
    char* string = calloc(n,sizeof(char));
    string[0] = 'A';
    string[1] = ' ';
    string[2] = 'm';
    string[3] = 'a';
    string[4] = 'n';
    string[5] = ',';
    string[6] = ' ';
    string[7] = 'a';
    string[8] = ' ';
    string[9] = 'p';
    string[10] = 'l';
    string[11] = 'a';
    string[12] = 'n';
    string[13] = ',';
    string[14] = ' ';
    string[15] = 'a';
    string[16] = ' ';
    string[17] = 'c';
    string[18] = 'a';
    string[19] = 'n';
    string[20] = 'a';
    string[21] = 'l';
    string[22] = ':';
    string[23] = ' ';
    string[24] = 'P';
    string[25] = 'a';
    string[26] = 'n';
    string[27] = 'a';
    string[28] = 'm';
    string[29] = 'a';
    string[30] = '\0';
    //char* string = "A man, a plan, a canal: Panama";
    printf("Before funtcall:\nString = %s\nArray Length(including null) = %d\n\n",string,n);
    if(isPalindrome(string) == true) printf("true\n");
    else printf("false\n");
    free(string);
    return 0;
}
