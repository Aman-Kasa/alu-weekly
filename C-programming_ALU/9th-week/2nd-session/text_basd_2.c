#include <stdio.h>
#include <stdlib.h>

typedef struct { char name[20]; int age, active; } Rec;
Rec r[100]; int n = 0;

void list()   { for(int i=0;i<n;i++) if(r[i].active) printf("%d. %s (%d)\n",i+1,r[i].name,r[i].age); }
void add()    { if(n<100){ printf("Name: "); scanf("%s",r[n].name); printf("Age: "); scanf("%d",&r[n].age); r[n].active=1; n++; } }
void edit()   { int i; printf("Num: "); scanf("%d",&i); if(i>0&&i<=n&&r[i-1].active){ scanf("%s%d",r[i-1].name,&r[i-1].age); } }
void del()    { int i; printf("Num: "); scanf("%d",&i); if(i>0&&i<=n&&r[i-1].active) r[i-1].active=0; }
void quit()   { exit(0); }

typedef void(*F)();
F menu[] = { list, add, edit, del, quit };
int en[] = {1,1,1,1,1}, sz = 5;

int main() {
    while(1) {
        for(int i=0;i<sz;i++) if(en[i]) printf("%d. %s\n",i+1, i?"Add":"List"+(i>0));
        int c; scanf("%d",&c); c--;
        if(c<0||c>=sz||!en[c]){ puts("Invalid"); continue; }
        menu[c]();
        en[3] = 0; for(int i=0;i<n;i++) if(r[i].active) en[3]=1; // disable Delete if empty
    }
}
