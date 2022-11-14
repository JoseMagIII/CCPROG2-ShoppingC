/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts learned. I
have constructed the functions and their respective algorithms and corresponding code by myself. The program was run, tested,
and debugged by my own efforts. I further certify that I have not copied in part or whole or otherwise plagiarized the work of
other students and/or persons.
Jose D. Maglaque III, DLSU ID# 11923571
*********************************************************************************************************/


/*
	Description:    This program is a program for online shopping. This program 
					allows users to either sell or buy products to/from other users.
					The user can easily keep track of what the other users are selling
					through this program. The user can also easily add his/her own
					products to sell using this program.
			
					
	Programmed By:	Jose D. Maglaque III  S14
	Last Modified: 	5/3/2020
	Version: 		1.0

*/

#include <stdio.h>
#include <string.h>
#include <conio.h>


typedef struct userTag
{
	int userID;
	char password[12];
	char address[32];
	int contactnum;
	char name[22];
	
	
}userType;

typedef struct itemTag
{
	int prodID;
	char name[22];
	char category[22];
	char description[32];
	int quantity;
	float price;
	int sellerID;	
	
	
}itemType;

typedef struct dateTag
{
	int month;
	int day;
	int year;
	
		
	
}dateType;

typedef struct cartTag
{
	itemType items[10];
	int cartCount;
	
	
}cartType;


typedef struct transTag
{
	dateType date;
	itemType aItems[5];
	int sellID;
	int buyID;
	float totalAmount;	
	
}transType;

typedef struct sellerTag
{
	int ID;
	char name[22];
	int sales;
	float totalBought;
		
}sellerType;


void removeEnter(char word[])
{
	word[strlen(word)-1] = '\0';
	
}

int checkID(int ID, userType array[], int userCount)
{
	int marker = 0, ctr;
	
	for(ctr = 0; ctr < userCount; ctr++)
	{
		if(ID == array[ctr].userID)
		marker = 1;
		
		
		
	}
	
	return marker;
	
}

int checkitemID(int ID, itemType array[], int itemCount)
{
	int marker = 0, ctr;
	
	
	for(ctr = 0; ctr < itemCount; ctr++)
	{
		if(ID == array[ctr].prodID)
		{
		marker = 1;
		}
	if(marker)
	return ctr;

	}

	
	return -1;
	
	
	
	
}


/* This function allows the user to register.
	@param *User is a pointer to where the user's information will be saved
	@param aUser[] is an array of all the users registered in the program
	@param userCounter is the number of users registered in the program
	
*/


void registerUser(userType *User, userType aUser[], int userCounter)
{
	int ctr;
	char cDump;
	userType temp;
	
	printf("Input Name: ");
	fgets(temp.name, 100, stdin);
	removeEnter(temp.name);
	
	printf("Input Password: ");
	fgets(temp.password, 12, stdin);
	removeEnter(temp.password);
	
	do
	{
	
	
	printf("Input Unique ID: ");
	scanf("%d%c", &temp.userID, &cDump);
	
	if(checkID(temp.userID, aUser, userCounter))
	printf("User ID Taken!\nPlease Try Again!\n\n");
	}while(checkID(temp.userID, aUser, userCounter));
		

	printf("Input Contact Number: ");
	scanf("%d%c", &temp.contactnum, &cDump);
	
	printf("Input Address: ");
	fgets(temp.address, 32, stdin);
	removeEnter(temp.address);
	
	printf("Registering Complete!\n\n\n");
	
	*User = temp;
	
}

/* This function finds where the ID is located in the array of users
	@param ID is the ID that needs to be found in the array of users
	@param aUser[] is an array of all the users registered in the program
	@param userCnt is the number of users registered in the program
	
*/


int findID(int ID, userType aUser[], int userCnt)
{
	int index = -1, ctr;
	
	for(ctr = 0; ctr < userCnt; ctr++)
	if(ID == aUser[ctr].userID)
	index = ctr;
	
	
	return index;
}

/* This function checks if the password entered by the user matches his/her password
	@param index is where the user's information is located in the array of users
	@param aUser[] is an array of all the users registered in the program
	@param password is the password entered by the user
	
*/

int checkPassword(int index, char password[], userType aUser[])
{
	if(strcmp(password, aUser[index].password) == 0)
	return 0;
	
	else 
	return 1;
	
}

/* This function allows the user to add items for sale
	@param *item is the pointer to where the item information will be stored
	@param *itemCount is the pointer to where the number of items is stored
	@param aItems[] is the array of items for sale
	
*/


int addItem(itemType aItems[], int ID, itemType *item, int *itemCount)
{
	int ctr, userItems = 0;
	itemType temp;
	char cDump;
	
	for(ctr = 0; ctr < *itemCount; ctr++)
	if(aItems[ctr].sellerID == ID)
	userItems++;
	printf("\n\n");
	if(userItems < 20)
	{
		printf("Input Item Name: ");
		fgets(temp.name, 22, stdin);
		fgets(temp.name, 22, stdin);
		removeEnter(temp.name);
		
		do
		{
		
		
		printf("Input Item ID: ");
		scanf("%d%c", &temp.prodID, &cDump);
		
		if(checkitemID(temp.prodID, aItems, *itemCount) != -1)
		printf("Item ID already taken!\n\n");
		}while(checkitemID(temp.prodID, aItems, *itemCount) != -1);
		
		printf("Input Category: ");
		fgets(temp.category, 22, stdin);
		removeEnter(temp.category);
		
		printf("Input Quantity: ");
		scanf("%d%c", &temp.quantity, &cDump);
		
		printf("Input Price: ");
		scanf("%f%c", &temp.price, &cDump);
		
		printf("Input Short Description: ");
		fgets(temp.description, 32, stdin);
		removeEnter(temp.description);
		temp.sellerID = ID;
		
		*item = temp;
		*itemCount = *itemCount + 1;
		
		
	}
	
	else
	{
	printf("Item Limit Reached!\n\n");
	}
	
	printf("\n\n");
}

/* This function swaps the location of two existing items
	@param *item1 is a pointer to where the first item is located
	@param *item2 is a pointer to where the second item is located
	
*/


void swap(itemType *item1, itemType *item2)
{
	itemType copy;
	
	copy = *item1;
	*item1 = *item2;
	*item2 = copy;
}

/* This function sorts the item array based on their product ID from lowest to highest
	@param items[] array where all the item information is stored
	@param numItems number of items stored in the program
	
*/

void sortByID(itemType items[], int numItems)
{
	int ctr = 0, ctr2 = 0;
	
	for(ctr2 = 0; ctr2 < numItems; ctr2++)
	{
		for(ctr = 0; ctr < numItems; ctr++)
		{
	
			if(items[ctr].prodID > items[ctr2].prodID)
			{
				swap(&items[ctr], &items[ctr2]);
			}
	
		}
	}
	
	


	
}

/* This function "removes" all the information stored in the item structure
	@param *item is a pointer to where the item information is located
	
*/


void removeItem(itemType *item)
{
	itemType empty;
	strcpy(empty.category, "empty");
	strcpy(empty.description, "empty");
	strcpy(empty.name, "empty");
	empty.price = 0;
	empty.prodID = 0;
	empty.quantity = 0;
	empty.sellerID = 0;
	
	*item = empty;
	
	
	
	
}

/* This function displays the items of a user
	@param ID is the ID of the user 
	@param aItems[] is the array which has all the items registered in the program
	@param itemCount is the number of items for sale
	
*/

void display(itemType aItems[], int ID, int itemCount)
{
	itemType myItems[20];
	int ctr = 0, ctr2 = 0;
	printf("\n\n");
	
	
	for(ctr = 0; ctr < itemCount; ctr++)
	if(aItems[ctr].sellerID == ID)
	{
	myItems[ctr] = aItems[ctr];
	ctr2++;
	}

	sortByID(myItems, ctr2-1);
	
	
	
	
	printf("%8s|%15s      |%15s    |%s|%s|\n", "Product ID", "Item Name", "Category", "Unit Price", "Quantity");
	for(ctr = 0; ctr < ctr2; ctr++)
	{
	
	if(myItems[ctr].prodID != 0)
	printf("%10d|%-15s      |%-10s         |%10.2f|%8d|\n", myItems[ctr].prodID, myItems[ctr].name, myItems[ctr].category, myItems[ctr].price, myItems[ctr].quantity);
	
	else
	ctr2++;
	}
	
	printf("\n\n");
	
	for(ctr = 0; ctr < 20; ctr++)
	removeItem(&myItems[ctr]);
}

/* This function allows the user to edit the information of his items
	@param *item is a pointer to where the item information is located
	
*/


void editStock(itemType *item)
{
	int choice, quantity;
	char cDump;
	float newprice;
	char newName[22], newCat[22], newDesc[32];
	

	

		printf("\n\n");
	

		
		do
		{
		printf("#1: Replenish\n");
		printf("#2: Change Price\n");
		printf("#3: Change Item Name\n");
		printf("#4: Change Category\n");
		printf("#5: Change Description\n");
		printf("#6: Finish Editing\n");
		printf("Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("Input Quantity to be Added: ");
					scanf("%d", &quantity);
					(*item).quantity = (*item).quantity + quantity;
					break;
				
			case 2: printf("Input New Price: ");
					scanf("%f", &newprice);
					(*item).price = newprice;
					break;
				
			case 3: printf("Input New Name: ");
					fgets(newName, 22, stdin);
					fgets(newName, 22, stdin);
					removeEnter(newName);
					strcpy((*item).name, newName);
					break;
					
			case 4: printf("Input New Category: ");
					fgets(newCat, 22, stdin);
					fgets(newCat, 22, stdin);
					removeEnter(newCat);
					strcpy((*item).category, newCat);
					break;
				
			case 5: printf("Input New Description: ");
					fgets(newDesc, 32, stdin);
					fgets(newDesc, 32, stdin);
					removeEnter(newDesc);
					strcpy((*item).description, newDesc);
					break;
				
			case 6:	
					break;
			
			
		}
		}while(choice != 6);
		
		
}

/* This function prints the sell menu and allows the user to add new items, see his/her items for sale
   and edit the information of his/her items.
	@param ID is the ID of the user
	@param aItems[] is the array in which all the item information is stored
	@param *itemCount is the pointer in which the number of items is stored
	
*/

void SellMenu(itemType aItems[], int ID, int *itemCount)
{
	int choice;
	int index = -1, ctr, itemID;
	int ctr2;
	char lowpriceChoice, cDump;
	do
	{
	printf("\n\n");
	printf("#1: Add New Item\n");
	printf("#2: Edit Stock\n");
	printf("#3: Show My Products\n");
	printf("#4: Show My Low Stock Products\n");
	printf("#5: Exit Sell Menu\n");
	printf("Choice: ");
	scanf("%d", &choice);


	
	switch(choice)
	{
		case 1: addItem(aItems, ID, &aItems[*itemCount], itemCount);
				// NOT SURE IF ITEMCOUNT IS INCREMENTING
				break;
				
		case 2: printf("Input Item ID: ");
				scanf("%d%c", &itemID, &cDump);

				for(ctr = 0; ctr < *itemCount; ctr++)
				{
						if(itemID == aItems[ctr].prodID)
						index = ctr;
				} 
				
				
				if(index > -1 && aItems[index].sellerID == ID)
				editStock(&aItems[index]);
				
				else
				printf("ID Not Found!\n\n");	
				break;
			
		case 3: display(aItems, ID, *itemCount);
				break;
				
				
		case 4: ctr = 0;
				do
				{
												
					if(aItems[ctr].sellerID == ID)
					if(aItems[ctr].quantity < 5)
					{
						printf("\n\n");
						printf("Name: %s\n", aItems[ctr].name);
						printf("Category: %s\n", aItems[ctr].category);
						printf("Description: %s\n", aItems[ctr].description);
						printf("Quantity: %d\n", aItems[ctr].quantity);
						printf("Price: %.2f\n", aItems[ctr].price);
						printf("Product ID: %d\n", aItems[ctr].prodID);
						
						printf("\nType N to show next and X to stop:");	
						scanf("%c", &lowpriceChoice);
						scanf("%c", &lowpriceChoice);
						if(lowpriceChoice == 'N' || lowpriceChoice == 'n' )
						ctr++;

					}
					
					if(aItems[ctr].sellerID != ID || aItems[ctr].quantity >= 5) 
					ctr++;
				

				}while(ctr  < *itemCount && !(lowpriceChoice == 'X' ||  lowpriceChoice == 'x'));
				break;
			
		case 5: //exit
				break;
				
		
	}
	}while(choice != 5);
}

/* This function swaps the location of the information of two users
	@param *user1 is the pointer to where the first user's information is located
	@param *user2 is the pointer to where the second user's information is located
	
*/


void swapUser(userType *user1, userType *user2)
{
	userType temp;
	
	temp = *user1;
	*user1 = *user2;
	*user2 = temp;
	
	
	
	
	
}

/* This function sorts the IDs of the users from lowest to highest
	@param userCount is the number of users registered in the program
	@param aUser[] is the array of users in which all the user information is stored
	
*/


void sortuserID(userType aUser[], int userCount)
{
	int ctr, ctr2;
	
	for(ctr2 = 0; ctr2 < userCount; ctr2++)
	for(ctr = 0; ctr < userCount-ctr2; ctr++)
	if(aUser[ctr].userID > aUser[ctr+1].userID)
	swapUser(&aUser[ctr], &aUser[ctr+1]);
	
	
	
	
	
}

/* This function prints the receipt after the user has bought his/her items
	@param transCtr is the number of items the current transaction has
	@param transaction is the information of the current transaction
	
*/


void printReceipt(int transCtr, transType transaction)
{
	int ctr = 0, ctr2 = 0;
	
	printf("\n\n");
	printf("Receipt: \n");
	printf("Date: %d/%d/%d\n", transaction.date.month, transaction.date.day, transaction.date.year);
	printf("Buyer ID: %d\n", transaction.buyID);
	printf("Seller ID: %d\n\n", transaction.sellID);
	
	printf("Item Number\tItem Name\tQuantity\tPrice\n");
	for(ctr = 0; ctr < transCtr; ctr++)
	{

		
		printf("Item#%d\t\t%s\t\t%d\t\t%.2f", ctr+1, transaction.aItems[ctr].name, transaction.aItems[ctr].quantity, transaction.aItems[ctr].price);
		printf("\n");


	}
	printf("===================================================\n");
	printf("Total: %.2f", transaction.totalAmount);
	
}


/* This function removes all the items in a cart from a specific user
	@param item[] is the array in which all the item information is stored
	@param ID is the ID of the seller 
	@param cartCounter is the number of items in the cart
	
*/




void removeItemID(itemType item[], int ID, int cartCounter)
{
	int ctr = 0;
	for(ctr = 0; ctr < cartCounter; ctr++)
	{
		if(ID == item[ctr].sellerID)
		{
			removeItem(&item[ctr]);
			
		}
		
		
		
	}
	
	
	
}

/* This function allows the user to checkout the items from his/her cart
	@param cart is the user's cart where he/she added items
	@param cartCounter is how many items the user added to his/her cart
	@param aItems[] is where all the item information is stored
	@param itemCount is how many items are registered in the program
	@param userID is the ID of the user
	
*/


int checkout(cartType cart, int cartCounter, itemType aItems[], int itemCount, int userID)
{
	transType transaction;
	int checkoutChoice = 0;
	int index = 0, index2 = 0;
	int ctr = 0, ctr2 = 0;
	int ID = 0, transctr = 0, IDcnt = 0;
	int cartcount2 = cartCounter;

	removeItem(&transaction.aItems[0]);
	removeItem(&transaction.aItems[1]);
	removeItem(&transaction.aItems[2]);
	removeItem(&transaction.aItems[3]);
	removeItem(&transaction.aItems[4]);
	
	FILE *transpointer;
	transpointer = fopen("Transactions.dat", "ab");
	
	printf("Input Date of Transaction: \n");
	printf("Year: ");
	scanf("%d", &transaction.date.year);
	printf("Month: ");
	scanf("%d", &transaction.date.month);
	printf("Day: ");
	scanf("%d", &transaction.date.day);
	printf("\n\n");
	
	for(ctr = 0; ctr < cartCounter; ctr++)
	{
	
	index = checkitemID(cart.items[ctr].prodID, aItems, itemCount);
	
	if(cart.items[ctr].quantity > aItems[index].quantity)
	printf("%s Quantity has changed! %d remaining.\nYou can still edit your cart!\n", cart.items[ctr].name ,aItems[index].quantity);
	
	
	if(cart.items[ctr].price != aItems[index].price)
	printf("%s Price has changed! The new price is %.2f\nYou can stll edit your cart!\n", cart.items[ctr].name ,aItems[index].price);
	
	}
	
	do
	{
	
	printf("Checkout: \n");
	printf("#1: All Items\n");
	printf("#2: Specific Seller\n");
	printf("#3: Specific Item\n");
	printf("#4: Exit Checkout\n");
	printf("Choice: ");
	scanf("%d", &checkoutChoice);
	
	switch(checkoutChoice)
	{
		case 1: index = 0;
				transctr = 0;
				index2 = 0;
				ID = 0;
				transaction.totalAmount = 0; 
				transaction.buyID = userID;

				for(ctr2 = 0; ctr2 < cartCounter; ctr2++)
				{
				if(cart.items[ctr2].sellerID != ID && cart.items[ctr2].sellerID != 0)
				{

				ID = cart.items[ctr2].sellerID;
					
				
				
				

				for(ctr = 0; ctr < cartCounter; ctr++)
				{
					if(ID == cart.items[ctr].sellerID)
					{
						transaction.sellID = ID;
						transaction.aItems[transctr] = cart.items[ctr];
						transaction.totalAmount = transaction.totalAmount + (transaction.aItems[transctr].quantity * transaction.aItems[transctr].price);
						index = checkitemID(transaction.aItems[transctr].prodID, aItems, itemCount);
						aItems[index].quantity = aItems[index].quantity - transaction.aItems[transctr].quantity;
						
						cartcount2--;
						transctr++;	
						
						if(transctr == 5)
						{
						
						printReceipt(transctr, transaction);
						fwrite(&transaction, sizeof(transaction), 1, transpointer);
						transctr = 0;
						transaction.totalAmount = 0;
						removeItem(&transaction.aItems[0]);
						removeItem(&transaction.aItems[1]);
						removeItem(&transaction.aItems[2]);
						removeItem(&transaction.aItems[3]);
						removeItem(&transaction.aItems[4]);
						printf("\n\n");	
						}
					}
				}
						if(transctr < 5 && transctr > 0)
						{
						
						printReceipt(transctr, transaction);
						fwrite(&transaction, sizeof(transaction), 1, transpointer);
						transaction.totalAmount = 0;
						transctr = 0;
						removeItem(&transaction.aItems[0]);
						removeItem(&transaction.aItems[1]);
						removeItem(&transaction.aItems[2]);
						removeItem(&transaction.aItems[3]);
						removeItem(&transaction.aItems[4]);
						printf("\n\n");
						}
				removeItemID(cart.items, ID, cartCounter);
				}
				}
				break;
				
				
		case 2: index = 0;
				transctr = 0;
				index2 = 0;
				ID = 0;
				transaction.totalAmount = 0; 
				
				
				printf("Enter Seller ID: ");
				scanf("%d", &ID);
				transaction.sellID = ID;
				transaction.buyID = userID;
				
				for(ctr = 0; ctr < cartCounter; ctr++)
				{
					if(ID == cart.items[ctr].sellerID)
					{
						transaction.aItems[transctr] = cart.items[ctr];
						transaction.totalAmount = transaction.totalAmount + (transaction.aItems[transctr].quantity * transaction.aItems[transctr].price);
						index = checkitemID(transaction.aItems[transctr].prodID, aItems, itemCount);
						aItems[index].quantity = aItems[index].quantity - transaction.aItems[transctr].quantity;
						
						cartcount2--;
						transctr++;	
						
						if(transctr == 5)
						{
						
						printReceipt(transctr, transaction);
						fwrite(&transaction, sizeof(transaction), 1, transpointer);
						transctr = 0;
						transaction.totalAmount = 0;
						removeItem(&transaction.aItems[0]);
						removeItem(&transaction.aItems[1]);
						removeItem(&transaction.aItems[2]);
						removeItem(&transaction.aItems[3]);
						removeItem(&transaction.aItems[4]);
						printf("\n\n");	
						}
					}
				}
						if(transctr < 5 && transctr > 0)
						{
						
						printReceipt(transctr, transaction);
						fwrite(&transaction, sizeof(transaction), 1, transpointer);
						transaction.totalAmount = 0;
						removeItem(&transaction.aItems[0]);
						removeItem(&transaction.aItems[1]);
						removeItem(&transaction.aItems[2]);
						removeItem(&transaction.aItems[3]);
						removeItem(&transaction.aItems[4]);
						printf("\n\n");
						}
				removeItemID(cart.items, ID, cartCounter);
				break;
			
		case 3: index = 0;
				transctr = 0;
				index2 = 0;
				ID = 0;
				printf("Enter Item ID: ");
				scanf("%d", &ID);
				
				index2 = checkitemID(ID, cart.items, 10);
				index = checkitemID(ID, aItems, itemCount);
				if(index != -1)
				if(index2 != -1)
				{
					transaction.aItems[transctr] = cart.items[index2];
					aItems[index].quantity = aItems[index].quantity - cart.items[index2].quantity;
					transaction.totalAmount = cart.items[index2].price * cart.items[index2].quantity;
					transaction.buyID = userID;
					transaction.sellID = aItems[index].sellerID;
					transctr++;
					
					printReceipt(transctr, transaction);
					

					removeItem(&cart.items[index2]);
					cartcount2--;
					fwrite(&transaction, sizeof(transaction), 1, transpointer);
					removeItem(&transaction.aItems[0]);
					removeItem(&transaction.aItems[1]);
					removeItem(&transaction.aItems[2]);
					removeItem(&transaction.aItems[3]);
					removeItem(&transaction.aItems[4]);
					printf("\n\n");
				}
				
				else
				printf("Item not found!\n\n");
				break;
				
		case 4: //EXIT;
				break;
		
		
		
		
	}
	}while(checkoutChoice != 4);
	
	return cartcount2;
}

/* This function sorts the user's cart based on the seller's ID from lowest to highest
	@param aitems[] is the array in which all the item information is stored
	@param cartCount is the number of items in the cart
	
*/


void sortCart(itemType aItems[], int cartCount)
{
	
	int ctr = 0, ctr2 = 0;
	
	for(ctr2 = 0; ctr2 < cartCount; ctr2++)
	{
		for(ctr = 0; ctr < cartCount-ctr2; ctr++)
		{
	
			if(aItems[ctr].sellerID > aItems[ctr+1].sellerID)
			{
				swap(&aItems[ctr], &aItems[ctr+1]);
			}
	
		}
	}
	
	
}

/* This function prints out the buy meny which allows the user to buy items from other sellers
	@param aitems[] is the array in which all the item information is stored
	@param userID is the ID of the user 
	@param itemCount is how many items are registered in the program
	@param userCount is how many users are registered in the program
	@param aUser[] is the array in which all the user information is stored
	
*/

void BuyMenu(int userCount, userType aUser[], itemType aItems[], int itemCount, int userID)
{
	int choice, ctr = 0, ctr2 = 0;
	char next = 'N', cDump;
	int ID, cartcounter = 0;
	char category[22];
	char key[22], *finder;
	cartType cart;
	int index = 0, quantity = 0, editchoice = 0, index2 = 0;
	FILE *cartPointer;
	
	char filename[22];
	

	
	sprintf(filename, "%d.bag", userID);
	
	
	cartPointer = fopen(filename, "rb");
	if(cartPointer != NULL)
	{
	
	fread(&cart, sizeof(cart), 1, cartPointer);
	cartcounter = cart.cartCount;
	fclose(cartPointer);
	remove(filename);
	
	}
	

	printf("\n\n");
	
	do
	{
	
	printf("#1: View All Products\n"); //check
	printf("#2: Show All Products of a Specific Seller\n"); //chheck
	printf("#3: Search Products  by Category\n"); //check
	printf("#4: Search Products by Name\n"); //check
	printf("#5: Add to Cart\n"); //check
	printf("#6: Edit Cart\n"); //check
	printf("#7: Check Out\n"); //check
	printf("#8: Exit Buy Menu\n");
	printf("Choice: ");
	scanf("%d%c", &choice, &cDump);
	
	printf("\n\n");
	switch(choice)
	{
		case 1: ctr = 0;
				sortuserID(aUser, userCount-1);
				do
				{
				printf("ID: %d", aUser[ctr].userID);
				display(aItems, aUser[ctr].userID, itemCount);
					
				printf("\nType N to show next and X to stop: ");
				scanf("%c%c", &next, &cDump);	
					
					
				ctr++;	
				}while(ctr < userCount && (next == 'N' || next == 'n'));
				break;
				
		case 2: printf("Input ID: ");
				scanf("%d%c", &ID, &cDump);
				printf("ID is %d",  ID);
				display(aItems, ID, itemCount);
				break;
				
		case 3: ctr = 0;
				printf("Input Category: ");
				fgets(category, 22, stdin);

				removeEnter(category);
				do
				{
				if(strcmp(category, aItems[ctr].category) == 0)
				{
				
					printf("\n\n");
					printf("Name: %s\n", aItems[ctr].name);
					printf("Category: %s\n", aItems[ctr].category);
					printf("Description: %s\n", aItems[ctr].description);
					printf("Quantity: %d\n", aItems[ctr].quantity);
					printf("Price: %.2f\n", aItems[ctr].price);
					printf("Product ID: %d\n", aItems[ctr].prodID);
					ctr++;
					
					printf("\nType N to show next and X to stop: ");
					scanf("%c", &next);	
				}
				else
				ctr++;
				}while(ctr < itemCount && (next == 'N'  || next == 'n'));

				break;
				
				
		case 4: ctr = 0;
				printf("Enter key to search: ");
				fgets(key, 22, stdin);
				removeEnter(key);
				next = 'N';
				
				do
				{
				finder = strstr(aItems[ctr].name, key);
				if(finder)
				{
					printf("Name: %s\n", aItems[ctr].name);
					printf("Category: %s\n", aItems[ctr].category);
					printf("Description: %s\n", aItems[ctr].description);
					printf("Quantity: %d\n", aItems[ctr].quantity);
					printf("Price: %.2f\n", aItems[ctr].price);
					printf("Product ID: %d\n", aItems[ctr].prodID);
					ctr++;
					
					printf("\nType N to show next and X to stop: ");
					scanf("%c", &next);
				}
				else
				ctr++;
				}while(ctr < itemCount && (next == 'N'  || next == 'n'));
				break;
		
		case 5: index = 0;
				do
				{
				do
				{
				printf("Enter Item ID: ");
				scanf("%d", &ID);
				index = checkitemID(ID, aItems, itemCount);
				if(index == -1)
				printf("ID not found\n\n");
				if(aItems[index].sellerID == userID)
				printf("You can't buy your own items!\n\n");
				}while(index == -1 || aItems[index].sellerID == userID);
				
				do
				{
				
				printf("Enter Quantity: ");
				scanf("%d", &quantity);
				if(quantity > aItems[index].quantity)
				printf("Low on stock, only %d remaining\n\n", aItems[index].quantity);
				}while(quantity > aItems[index].quantity);
				
				cart.items[cartcounter] = aItems[index];
				cart.items[cartcounter].quantity = quantity;
				
				printf("Add another item? (Y/N): ");
				scanf("%c", &next);
				scanf("%c", &next);
				cartcounter++;	
				}while(cartcounter <= 10 && (next == 'Y' || next == 'y'));
				if(cartcounter == 10)
				printf("Cart full! Please check out or edit cart!\n\n");
				break;
				
				
		case 6: index = 0;
				ID = 0;
				sortCart(cart.items, cartcounter-1);
				
				
				do
				{
				
				for(ctr = 0; ctr < cartcounter; ctr++)
				{
					
					if(ID != cart.items[ctr].sellerID)
					{
					ID = cart.items[ctr].sellerID;
					printf("ID: %d\n", ID);
					display(cart.items, ID, cartcounter);
					
					}
				}

				
				printf("#1: Remove Items from a Seller\n");
				printf("#2: Remove a Specific Item\n");
				printf("#3: Edit Quantity\n");
				printf("#4: Finish Editing Cart\n");
				printf("Choice: ");
				scanf("%d", &editchoice);
				
				switch(editchoice)
				{
					case 1: index = -1;
							printf("Input Seller ID: ");
							scanf("%d", &ID);
							for(ctr = 0; ctr < cartcounter; ctr++)
							{
								if(ID == cart.items[ctr].sellerID)
								index = ctr;
								
								if(index != -1)
								{
								swap(&cart.items[ctr], &cart.items[cartcounter-1]);
								cartcounter--;
								index = 0;
								}
								
							}
							break;
							
					case 2:	printf("Input Item ID: ");
							scanf("%d", &ID);
							for(ctr = 0; ctr < cartcounter; ctr++)
							{
								if(ID == cart.items[ctr].prodID)
								index = ctr;
							}
							swap(&cart.items[ctr], &cart.items[cartcounter-1]);
							cartcounter--;
							break;
							
					case 3: index = -1;
							do
							{
					
							printf("Input Item ID: ");
							scanf("%d", &ID);
							for(ctr = 0; ctr < cartcounter; ctr++)
							{
								if(ID == cart.items[ctr].prodID)
								index = ctr;
							}
							if(index == -1)
							printf("ID not found!\n\n");
							
							else
							{
								do
								{
								
								printf("Input new quantity: ");
								scanf("%d", &quantity);
								
								index2 = checkitemID(cart.items[index].prodID, aItems, itemCount);
								if(quantity > aItems[index2].quantity)
								printf("Low on stock, only %d remaining\n\n", aItems[index].quantity);
								
								else
								cart.items[index].quantity = quantity;
								
								}while(quantity > aItems[index2].quantity);
							}
							}while(index == -1);
							break;	
						
					case 4: //EXIT
							break;
					
					
				}
				}while(editchoice != 4);
				break;
		
		case 7: sortCart(cart.items, cartcounter-1);
				cartcounter = checkout(cart, cartcounter, aItems, itemCount, userID);
				break;
		
		case 8: 
				if(cartcounter != 0)
				{
					cart.cartCount = cartcounter;
					cartPointer = fopen(filename,  "wb");
					fwrite(&cart, sizeof(cart), 1, cartPointer);
					fclose(cartPointer);
				}
				break;
	}
	}while(choice != 8);
}

/* This function prints the usermenu which enables the user to choose from buying or selling
	@param aitems[] is the array in which all the item information is stored
	@param aUser[] is the array in which all the user information is stored
	@param userCnt is the number of users registed in the program
	@param *itemCount is the pointer to which how many items is registered in the program
	
*/


void UserMenu(userType aUser[], int userCnt, itemType aItems[], int *itemCount)
{
	char cDump, temppass[12];
	int index, ID, choice;

	
	printf("\n\nUserID: ");
	scanf("%d%c", &ID, &cDump);
	index = findID(ID, aUser, userCnt);
	
	
	if(index > -1)
	{
	
	do
	{
	
	printf("Password: ");
	fgets(temppass, 12, stdin);
	removeEnter(temppass);
	if(checkPassword(index, temppass, aUser))
	printf("Wrong Password!\nPlease Try Again!\n\n");
	
	}while(checkPassword(index, temppass, aUser));
	
	printf("\n\n");
	
	do
	{
	
	printf("#1: Sell Menu\n");
	printf("#2: Buy Menu\n");
	printf("#3: Exit User Menu\n");
	printf("Choice: ");
	scanf("%d%c", &choice, &cDump);
	
	switch(choice)
	{
		case 1: SellMenu(aItems, ID, itemCount);
				break;
		
		case 2: BuyMenu(userCnt, aUser, aItems, *itemCount, ID);
				break;
		
		case 3: //EXIT
				break;
				
		
	}
	}while(choice != 3);
	
	}
	else
	printf("ID not found!\n\n");
	
	printf("\n\n");
	
}

/* This function saves all the items registed in the program to a file names Items.txt
	@param aitems[] is the array in which all the item information is stored
	@param itemCount is the number of items registered in the program
	
*/


void saveItems(itemType aItems[], int itemCount)
{
	FILE *itemPointer;
	int ctr = 0;
	
	itemPointer = fopen("Items.txt", "w");
	
	for(ctr = 0; ctr < itemCount; ctr++)
	{
		fprintf(itemPointer, "%d %d\n", aItems[ctr].prodID, aItems[ctr].sellerID);
		fprintf(itemPointer, "%s\n", aItems[ctr].name);
		fprintf(itemPointer, "%s\n", aItems[ctr].category);
		fprintf(itemPointer, "%s\n", aItems[ctr].description);
		fprintf(itemPointer, "%d %.2f\n", aItems[ctr].quantity, aItems[ctr].price);
		fprintf(itemPointer, "\n");
		
	}
	
	fclose(itemPointer);
}

/* This function loads all the items saved in Items.txt
	@param aitems[] is the array in which all the item information is stored
	
*/

int loadItems(itemType aItems[])
{
	FILE *itemPointer;
	int ctr = 0;
	
	itemPointer = fopen("Items.txt", "r");
	
	while(fscanf(itemPointer, "%d %d\n", &aItems[ctr].prodID, &aItems[ctr].sellerID) != EOF)
		{
		fscanf(itemPointer, "%[^\n]\n", aItems[ctr].name);
		fscanf(itemPointer, "%[^\n]\n", aItems[ctr].category);
		fscanf(itemPointer, "%[^\n]\n", aItems[ctr].description);
		fscanf(itemPointer, "%d %f\n", &aItems[ctr].quantity, &aItems[ctr].price);
		fscanf(itemPointer, "\n");

		ctr++;
		}	
	fclose(itemPointer);
	
	return ctr;
}

/* This function saves all the users registered in the program in Users.txt
	@param aUser[] is the array in which all the user information is stored
	@param userCnt is the number of users registered in the program
	
*/

void saveUsers(userType aUser[], int userCnt)
{
	FILE *userPointer;
	int ctr = 0;
	
	userPointer = fopen("Users.txt", "w");
	
	for(ctr = 0; ctr < userCnt; ctr++)
	{
		fprintf(userPointer, "%d %s\n", aUser[ctr].userID, aUser[ctr].password);
		fprintf(userPointer, "%s\n", aUser[ctr].name);
		fprintf(userPointer, "%s\n", aUser[ctr].address);
		fprintf(userPointer, "%d\n", aUser[ctr].contactnum);
		fprintf(userPointer, "\n");
		
	}
	
	
	fclose(userPointer);
	
	
	
}

/* This function loads all the user information from Users.txt
	@param aUser[] is the array in which all the user information is stored
	
*/

int loadUsers(userType aUser[])
{
	FILE *userPointer;
	int ctr = 0;
	
	userPointer = fopen("Users.txt", "r");
	

		
	while(fscanf(userPointer, "%d %s\n", &aUser[ctr].userID, aUser[ctr].password) != EOF)
	{
	
		fscanf(userPointer, "%[^\n]\n", aUser[ctr].name);
		fscanf(userPointer, "%[^\n]\n", aUser[ctr].address);
		fscanf(userPointer, "%d\n", &aUser[ctr].contactnum);
		fscanf(userPointer, "\n");
		
		
		ctr++;
	}
	
	fclose(userPointer);
	
	return ctr;
	
}

/* This function loads all the previous transactions that happened
	@param aTransaction[] is the array of transactions where the transaction information will be stored
	
*/

int loadTransaction(transType aTransaction[])
{
	FILE *transPointer;
	int ctr = 0;
	
	transPointer = fopen("Transactions.dat", "rb");
	
	while(fread(&aTransaction[ctr], sizeof(transType), 1, transPointer))
	{
		ctr++;

	}
	
	
	return ctr;
}

/* This function finds the index where the seller ID is located
	@param seller[] is the array in which the seller information is stored
	@param sellercount is how many sellers there are
	@param ID is the seller ID that needs to be found
	
*/


int findsellerID(sellerType seller[], int sellercount, int ID)
{
	int ctr = 0;
	
	
	for(ctr = 0; ctr < sellercount; ctr++)
	{
		if(ID == seller[ctr].ID)
		return ctr;
		
		
	}
	
	return -1;
}

/* This function prints the admin menu for the admin
	@param aUser[] is the array where all the user information is stored
	@param aItems[] is the array where all the item information is stored
	@param userCnt is the number of users registered in the program
	@param itemCount is the number of items registered in the program
	
*/


void adminmenu(userType aUser[], itemType aItems[], int userCnt, int itemCount)
{
	char password[22];
	int choice = 0;
	int ctr = 0, ctr2 = 0;
	int userItems = 0;
	transType aTransaction[1000];
	int transcounter = 0;
	int year1 = 0, day1 = 0, month1 = 0, year2 = 0, day2 = 0, month2 = 0;
	float totalAmount = 0;
	int index = -1, sellercount = 0;
	
	sellerType seller[100];

	
	
	for(ctr = 0; ctr < 100; ctr++)
	{
		seller[ctr].sales = 0;	
		seller[ctr].totalBought = 0;
	}
	
	
	printf("\n\n");
	
	printf("Input Admin Password: ");
	fgets(password, 22, stdin);
	removeEnter(password);
	
	if(strcmp(password, "H3LLo") == 0)
	{
		transcounter = loadTransaction(aTransaction);
	
		do
		{
		printf("#1: Show All Users\n");
		printf("#2: Show All Sellers\n");
		printf("#3: Show Total Sales in Given Duration\n");
		printf("#4: Show Seller Sales\n");
		printf("#5: Show Shopaholics\n");
		printf("#6: Exit Admin Menu\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		printf("\n\n");
		switch(choice)
		{
			case 1: 
					
					for(ctr = 0; ctr < userCnt; ctr++)
					{
						printf("%-10d%-11s%-21s%-31s%-10d", aUser[ctr].userID, aUser[ctr].password, aUser[ctr].name ,aUser[ctr].address, aUser[ctr].contactnum);
						printf("\n");
					}
					printf("\n\n");
					break;
					
			case 2: 
					
					for(ctr = 0; ctr < userCnt; ctr++)
					{
						for(ctr2 = 0; ctr2 < itemCount; ctr2++)
						{
							if(aUser[ctr].userID == aItems[ctr2].sellerID)
							userItems++;
							
						}
						
						if(userItems > 0)
						{
						printf("%-10d%-11s%-21s%-31s%-10d%d\n", aUser[ctr].userID, aUser[ctr].password, aUser[ctr].name, aUser[ctr].address, aUser[ctr].contactnum, userItems);
						userItems = 0;
						}	
					}
					printf("\n\n");
					break;
					
					
			case 3: printf("Input Starting Date:\n");
					printf("Year: ");
					scanf("%d", &year1);
					printf("Month: ");
					scanf("%d", &month1);
					printf("Day: ");
					scanf("%d", &day1);
					
					printf("\n\n");
					printf("Input End Date:\n");
					printf("Year: ");
					scanf("%d", &year2);
					printf("Month: ");
					scanf("%d", &month2);
					printf("Day: ");
					scanf("%d", &day2);
					
					if(transcounter == 0)
					printf("\n\nNo Transaction Found!\n\n");
					
					else
					{
					
					for(ctr = 0; ctr < transcounter; ctr++)
					{
					if(aTransaction[ctr].date.year >= year1 && aTransaction[ctr].date.year <= year2)
					if((aTransaction[ctr].date.month >= month1 && aTransaction[ctr].date.month <= month2) || (aTransaction[ctr].date.year > year1 && aTransaction[ctr].date.year < year2))
					if((aTransaction[ctr].date.day >= day1 && aTransaction[ctr].date.day <= day2) || (aTransaction[ctr].date.month > month1 && aTransaction[ctr].date.month < month2) || (aTransaction[ctr].date.year > year1 && aTransaction[ctr].date.year < year2))
						totalAmount = totalAmount + aTransaction[ctr].totalAmount;
						
					}
					
					printf("\n\n");
					printf("%d/%d/%d to %d/%d/%d\n", year1,month1,day1,year2,month2,day2);
					printf("Total Sales: %.2f", totalAmount);
					}
					printf("\n\n");
					break;
				
			case 4: sellercount = 0;
					printf("Input Starting Date:\n");
					printf("Year: ");
					scanf("%d", &year1);
					printf("Month: ");
					scanf("%d", &month1);
					printf("Day: ");
					scanf("%d", &day1);
					
					printf("\n\n");
					printf("Input End Date:\n");
					printf("Year: ");
					scanf("%d", &year2);
					printf("Month: ");
					scanf("%d", &month2);
					printf("Day: ");
					scanf("%d", &day2);
					
					if(transcounter == 0)
					printf("No Transaction Found!\n\n");					
					
					for(ctr = 0; ctr < transcounter; ctr++)
					{
					if(aTransaction[ctr].date.year >= year1 && aTransaction[ctr].date.year <= year2)
					if((aTransaction[ctr].date.month >= month1 && aTransaction[ctr].date.month <= month2) || (aTransaction[ctr].date.year > year1 && aTransaction[ctr].date.year < year2))	
					if((aTransaction[ctr].date.day >= day1 && aTransaction[ctr].date.day <= day2) || (aTransaction[ctr].date.month > month1 && aTransaction[ctr].date.month < month2) || (aTransaction[ctr].date.year > year1 && aTransaction[ctr].date.year < year2))
					 {
					 					
					 	
						if(findsellerID(seller, sellercount, aTransaction[ctr].sellID) == -1)
						{  
						seller[sellercount].ID = aTransaction[ctr].sellID;
					 	index = findID(seller[sellercount].ID, aUser, userCnt);
					 	strcpy(seller[sellercount].name, aUser[index].name);
					 	seller[sellercount].sales++;
					 	sellercount++;
					 	}
					 	
					 	else
					 	{
					 	seller[findsellerID(seller, sellercount, aTransaction[ctr].sellID)].sales++;	
						}
					 }
					}
					
					printf("SELLER ID\t\tSELLER NAME\t\tTOTAL SALES\n");
					for(ctr = 0; ctr < sellercount; ctr++)
					{
						printf("%-10d%-21s%d\n", seller[ctr].ID, seller[ctr].name, seller[ctr].sales);		
					}
					
					printf("\n\n");
					break;
				
			case 5: sellercount = 0;
					printf("Input Starting Date:\n");
					printf("Year: ");
					scanf("%d", &year1);
					printf("Month: ");
					scanf("%d", &month1);
					printf("Day: ");
					scanf("%d", &day1);
					
					printf("\n\n");
					printf("Input End Date:\n");
					printf("Year: ");
					scanf("%d", &year2);
					printf("Month: ");
					scanf("%d", &month2);
					printf("Day: ");
					scanf("%d", &day2);
					
					if(transcounter == 0)
					printf("No Transaction Found!\n\n");					
					

					for(ctr = 0; ctr < transcounter; ctr++)
					{
					if(aTransaction[ctr].date.year >= year1 && aTransaction[ctr].date.year <= year2)
					if((aTransaction[ctr].date.month >= month1 && aTransaction[ctr].date.month <= month2) || (aTransaction[ctr].date.year > year1 && aTransaction[ctr].date.year < year2))
					if((aTransaction[ctr].date.day >= day1 && aTransaction[ctr].date.day <= day2) || (aTransaction[ctr].date.month > month1 && aTransaction[ctr].date.month < month2) || (aTransaction[ctr].date.year > year1 && aTransaction[ctr].date.year < year2))
					 {
					 	
						if(findsellerID(seller, sellercount, aTransaction[ctr].sellID) == -1)
						{  
						seller[sellercount].ID = aTransaction[ctr].buyID;
					 	index = findID(seller[sellercount].ID, aUser, userCnt);
					 	strcpy(seller[sellercount].name, aUser[index].name);
					 	seller[sellercount].totalBought = aTransaction[ctr].totalAmount;
					 	sellercount++;
					 	}
					 	
					 	else
					 	{
					 	seller[findsellerID(seller, sellercount, aTransaction[ctr].sellID)].totalBought = seller[findsellerID(seller, sellercount, aTransaction[ctr].sellID)].totalBought + aTransaction[ctr].totalAmount;	
						}
					 }
					}
					
					
					printf("BUYER ID\t\tSELLER NAME\t\tTOTAL BOUGHT\n");
					for(ctr = 0; ctr < sellercount; ctr++)
					{
						printf("%d\t\t\t\%s\t\t\t%.2f\n", seller[ctr].ID, seller[ctr].name, seller[ctr].totalBought);		
					}
					
					printf("\n\n");
					
					break;
				
			case 6: //EXIT		
					break;
		}
		
		
		
		
		}while(choice != 6);	
		
	}
	
	
	
	else
	printf("Unauthorized access not allowed\n\n");
	
	
}

int main()
{
	userType aUser[100];
	itemType aItems[2000];
	transType sTrans;
	int userCnt = 0, itemCount  = 0, choice;
	
	

	
	userCnt = loadUsers(aUser);
	itemCount = loadItems(aItems);
	char cDump;

	do
	{
	
	printf("#1: Register\n");
	printf("#2: Menu\n");
	printf("#3: Admin Menu\n");
	printf("#4: Exit\n");

	

		
	printf("\nChoice: ");
	scanf("%d%c", &choice, &cDump);
	
	switch(choice)
	{
		case 1: registerUser(&aUser[userCnt], aUser, userCnt);
				userCnt++;
				break;
		
		case 2: UserMenu(aUser, userCnt, aItems, &itemCount);
				break;
		
		case 3: adminmenu(aUser, aItems, userCnt, itemCount);
				break;
		
		case 4: saveItems(aItems, itemCount);
				saveUsers(aUser, userCnt);
				break;
	}
	
	
	}while(choice != 4);
	
	
}




