/**
 * Task:
 * Create a struct for a book, including title, author, pages, and price.
 * 
 * Extra:
 * Write a function that prints Book information.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * struct book - represents a book
 * @title: title of the book
 * @author: author of the book
 * @pages: number of pages in the book
 * @price: price of the book
 */
struct book
{
	char *title;
	char *author;
	int pages;
	float price;
};

/**
 * print_book - prints the information of a book
 * @b: pointer to the struct book
 *
 * Description: Displays all information about the book.
 */
void print_book(struct book *b)
{
	if (b == NULL)
	{
		printf("No book information available.\n");
		return;
	}

	printf("📘 Title: %s\n", b->title);
	printf("👤 Author: %s\n", b->author);
	printf("📄 Pages: %d\n", b->pages);
	printf("💰 Price: $%.2f\n", b->price);
}

/**
 * main - entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	struct book my_book = {"The C Programming Language", "Thadee", 400, 79.99};

	print_book(&my_book);

	return (0);
}

