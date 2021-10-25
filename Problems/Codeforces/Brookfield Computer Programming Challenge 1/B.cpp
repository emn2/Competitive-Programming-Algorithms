#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char obj1[1001], obj2[1001];
        scanf(" I have a %s", obj1);
        scanf(" I have a %s", obj2);
        printf("Uh! %s-%s!\n", obj2, obj1);
    }
    
    return 0;
}
