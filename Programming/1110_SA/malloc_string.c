#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
    int n, len;
    unsigned int max = 0, min = INT_MAX;
    scanf("%d", &n);

    char **words = malloc(n * sizeof(char*));

    char tmp[105];
    
    for(int i = 0; i < n; i++) {
        // Read
        fgets(tmp, sizeof(tmp), stdin);
        tmp[strscpn(tmp, '\n')] = '\0'; // remove \n
        
        // Update Max / Min
        len = strlen(tmp);
        if (len > max) max = len;
        if (len < min) min = len;
        
        // Put into words
        words[i] = malloc(100 * sizeof(char)); 
        strcpy(words[i], tmp);        
    }

    // Output min 
    printf("最短字串: 長度%u\n", min);
    for(int i = 0; i < n; i++) {
        if (strlen(words[i]) == min) {
            print;
        }
    }

    
    return 0;
}