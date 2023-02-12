#include <stdio.h>
int ord[20][5];
char size;
int cat;
int i;
char mi;
char crust;

void menu()
{
    printf("\n\t\t\t\t\tWelcome To PIZZA MANIA\n\n");
    printf("Category\tPersonal\tMedium\t\tLarge\t\tPizza\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Classic\t\tRs.490.00\tRs.940.00\tRs.1710.00\t01.Chicken Bacon\n");
    printf("\t\t\t\t\t\t\t\t02.Cheese Lovers\n");
    printf("\t\t\t\t\t\t\t\t03.Devilled Chicken\n");
    printf("\t\t\t\t\t\t\t\t04.Sausage Delight\n");
    printf("\t\t\t\t\t\t\t\t05.Tandoori Chicken\n");
    printf("Signature\tRs.555.00\tRs.1030.00\tRs.1880.00\t06.Hot & Spicy Chicken\n");
    printf("\t\t\t\t\t\t\t\t07.Double Chicken & Cheese Fiesta\n");
    printf("\t\t\t\t\t\t\t\t08.Chicken Hawaiian\n");
    printf("\t\t\t\t\t\t\t\t09.Butter Chicken Masala\n");
    printf("\t\t\t\t\t\t\t\t10.Hot Butter Cuttlefish\n");
    printf("\t\t\t\t\t\t\t\t11.BBQ Chicken\n");
    printf("Favorite\tRs.590.00\tRs.1130.00\tRs.2070.00\t12.Devilled Beef\n");
    printf("\t\t\t\t\t\t\t\t13.Triple Chicken Feast\n");
    printf("\t\t\t\t\t\t\t\t14.Spicy Seafood\n");
    printf("\t\t\t\t\t\t\t\t15.Meat Lovers Chicken\n");
    printf("\t\t\t\t\t\t\t\t16.Veggie Supreme\n");
    printf("Supreme\t\tRs.735.00\tRs.1410.00\tRs.2540.00\t17.Super Supreme\n");
    printf("\t\t\t\t\t\t\t\t18.Hot Garlic Prawns\n");
    printf("Stuffed Crust = +Rs.170.00\n");
}

void order()
{
   for(i=0;i<20;i++)
    {

        printf("\n***ENTER ANYTHING NOT IN THE MENU TO EXIT***\n");
        printf("Enter Pizza Number: ");scanf("%d",&ord[i][0]);
        if (ord[i][0]>=17 && ord[i][0]<19)
        {
            cat=4;
        }
        else if (ord[i][0]>=12 && ord[i][0]<19)
        {
            cat=3;
        }
        else if (ord[i][0]>=6 && ord[i][0]<19)
        {
            cat=2;
        }
        else if(ord[i][0]>=1 && ord[i][0]<19)
        {
            cat=1;
        }
        else
        {
            printf("Invalid Number\n\n");
            break;
        }
        printf("Enter Size(S,M,L): ");scanf(" %c",&size);
        if (size=='s' || size=='S')
        {
            ord[i][1]=1;
            if (cat==1)
            {
                ord[i][4]=490;
            }
            else if (cat==2)
            {
                ord[i][4]=555;
            }
            else if (cat==3)
            {
                ord[i][4]=590;
            }
            else if (cat==4)
            {
                ord[i][4]=735;
            }
        }
        else if(size=='m' || size=='M')
        {
            ord[i][1]=2;
            if (cat==1)
            {
                ord[i][4]=940;
            }
            else if (cat==2)
            {
                ord[i][4]=1030;
            }
            else if (cat==3)
            {
                ord[i][4]=1130;
            }
            else if (cat==4)
            {
                ord[i][4]=1410;
            }
        }
        else if(size=='L' || size=='l')
        {
            ord[i][1]=3;
            if (cat==1)
            {
                ord[i][4]=1710;
            }
            else if (cat==2)
            {
                ord[i][4]=1880;
            }
            else if (cat==3)
            {
                ord[i][4]=2070;
            }
            else if (cat==4)
            {
                ord[i][4]=2540;
            }
        }
        else
        {
            printf("Invalid Size\n\n");
            break;
        }
        printf("Pan Crust or Stuffed Crust?(p/s): ");scanf(" %c",&crust);
        if (crust=='s' || crust=='S' || crust=='p' || crust=='P')
        {
            if (crust=='s' || crust=='S')
            {
                ord[i][2]=2;
                ord[i][4]=ord[i][4]+170;
            }
            else
            {
                ord[i][2]=1;
            }
        }
        else
        {
            printf("Invalid Crust Type");
            break;
        }
        printf("Enter Quantity: ");scanf("%d",&ord[i][3]);
        printf("Add more items(y/n): ");scanf(" %c",&mi);
        if (mi=='n' || mi=='N')
        {
            break;
        }
    }
}
void bill()
{
    float total=0;
    system("cls");
    printf("PizzaID\tSize\tCrust\tPrice\tQuantity\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(i=0;i<20;i++)
    {
        if (ord[i][0]==0 || ord[i][0]<0 || ord[i][0]>=19)
        {
            break;
        }
        if (ord[i][1]==1)
        {
            size='S';
        }
        if (ord[i][1]==2)
        {
            size='M';
        }
        if (ord[i][1]==3)
        {
            size='L';
        }
        if (ord[i][2]==1)
        {
            crust='P';
        }
        if (ord[i][2]==2)
        {
            crust='S';
        }
        printf("%d\t",ord[i][0]);
        printf("%c\t",size);
        printf("%c\t",crust);
        printf("Rs.%d\t",ord[i][4]);
        printf("x%d\t",ord[i][3]);
        printf("\n");
        total=total+(ord[i][4]*ord[i][3]);
    }
    printf("\n\t\t\tTotal: \tRs.%0.2f\n\n",total);
}
void main()
{
    char repeat;
    while (1)
    {
        menu();
        order();
        bill();
        printf("Another Order(y/n): ");scanf(" %c",&repeat);
        if (repeat=='n'||repeat=='N')
            break;
        else
            system("cls");
    }
    return (0);
}
