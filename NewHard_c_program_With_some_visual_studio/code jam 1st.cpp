#include<stdio.h>
int f1();
main()
{
    int N;

    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    f1();

}
int f1()

    {
        static int j=1;
        int C ;//C=Credit
        scanf("%d",&C);
        int L; //L =n(Items) in the list
        scanf("%d",&L);
        int I[L] ; //Item array
        for(int a=0;a<L;a++)
            scanf("%d",&I[a]);

        for(int e=0;e<L;e++)
        {
            for(int f=e+1;f<L;f++)




            if(I[e]+I[f]==C) {
                printf("Case #%d: %d %d\n",j,e+1,f+1);

                j++;
                return 0;
            }



        }
    return 0;
    }



