#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct barSnackes
{
    int unit_price,quantity;
    char item_name[20];
    double total;
};
int main()
{
    char customer_name[20];
    int no_of_item;
    double sum = 0;
    printf("Please enter the name of the customer : ");
    fflush(stdin);
    gets(customer_name);
    printf("\nPlease enter number of items to snacks : ");
    scanf("%d",&no_of_item);
//time function working method
    time_t currentTime;
    time(&currentTime);

    struct barSnackes product[no_of_item];
    for(int i = 0 ; i<no_of_item ; i++)
    {
        printf("\n\nPlease enter the item %d : ",i +1);
        fflush(stdin);
        gets(product[i].item_name);
        printf("Please enter the unit price : ");
        scanf("%d",&product[i].unit_price);
        printf("Please enter the quantity : ");
        scanf("%d",&product[i].quantity);
        product[i].total = product[i].quantity * product[i].unit_price;
        sum = sum + product[i].total;
    }

    printf("\n\n\t\t\t My Restaurant");
    printf("\n\t\t--------------------------------");
    printf("\n\n%s",ctime(&currentTime));
    printf("Invoice To : %s\n",customer_name);
    printf("------------------------------------------------------\n");
    printf("\tItems\t\tQty\t\tTotal\n");
    printf("------------------------------------------------------\n\n");
    for(int j = 0 ; j<no_of_item ; j++)
    {
        printf("\t%s\t\t%d\t\t%.2lf\n",product[j].item_name,product[j].quantity,product[j].total);
    }
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("\tSub Total\t\t\t%.2lf",sum);
    double discount = (float)sum * 0.1;
    printf("\n\tDiscount @10%\t\t\t%.2lf",discount);
    printf("\n\t\t\t\t   ------------------");
    double sub = sum - discount;
    printf("\n\tNet Total\t\t\t%.2lf",sub);
    double cgst,sgst;
    cgst = (float)sub * 0.09;
    sgst = (float)sub * 0.09;
    printf("\n\tCGST @9%\t\t\t\t%.2lf",cgst);
    printf("\n\tSGST @9%\t\t\t\t%.2lf",sgst);
    printf("\n------------------------------------------------------\n");
    double grand_total = cgst + sgst + sub;
    printf("\tGrand Total\t\t\t%.2lf\n",grand_total);




    return 0 ;
}
