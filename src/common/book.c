#include <stdio.h>
#include "book.h"
#include <time.h>
#include <stdlib.h>



struct book** generate_books(size_t length) {
    //srand(time(NULL));   // Initialization, should only be called once.
    struct book available_books[] = {
            {.title = "In Search of Lost Time", .authors = "Marcel Proust", .tags = "Novel", .annotation = "Swann's Way, the first part of A la recherche de temps perdu, Marcel Proust's seven-part cycle, was published in 1913. In it, Proust introduces the themes that run through the entire work. The narrator recalls his childhood, aided by the famous madeleine; and describes M. Swann's passion for Odette."},
            {.title = "Ulysses", .authors = "James Joyce", .tags = "Novel", .annotation = "Ulysses chronicles the passage of Leopold Bloom through Dublin during an ordinary day, June 16, 1904. The title parallels and alludes to Odysseus (Latinised into Ulysses), the hero of Homer's Odyssey (e.g., the correspondences between Leopold Bloom and Odysseus, Molly Bloom and Penelope, and Stephen Dedalus and Telemachus)."},
            {.title = "Don Quixote", .authors = "Miguel de Cervantes", .tags = "Novel", .annotation = "Alonso Quixano, a retired country gentleman in his fifties, lives in an unnamed section of La Mancha with his niece and a housekeeper. He has become obsessed with books of chivalry, and believes their every word to be true, despite the fact that many of the events in them are clearly impossible."},
            {.title = "One Hundred Years of Solitude", .authors = "Gabriel Garcia Marquez", .tags = "Novel", .annotation = "One of the 20th century's enduring works, One Hundred Years of Solitude is a widely beloved and acclaimed novel known throughout the world, and the ultimate achievement in a Nobel Prize–winning career. The novel tells the story of the rise and fall of the mythical town of Macondo through the history of the Buendía family."},
            {.title = "The Great Gatsby", .authors = "F. Scott Fitzgerald", .tags = "Novel", .annotation = "The novel chronicles an era that Fitzgerald himself dubbed the \"Jazz Age\". Following the shock and chaos of World War I, American society enjoyed unprecedented levels of prosperity during the \"roaring\" 1920s as the economy soared."},
            {.title = "Moby Dick", .authors = "Herman Melville", .tags = "Novel", .annotation = "First published in 1851, Melville's masterpiece is, in Elizabeth Hardwick's words, \"the greatest novel in American literature.\" The saga of Captain Ahab and his monomaniacal pursuit of the white whale remains a peerless adventure story but one full of mythic grandeur, poetic majesty, and symbolic power."},

    };
    struct book **books = calloc(length+1, sizeof(struct book *));
    for (size_t i = 0; i < length; i++) {
        books[i] = calloc(1, sizeof(struct book));
        books[i]->bookID = i;
        books[i]->available = MAX_BOOKS_AMOUNT;

        //int r = rand() % 3;      // Returns a pseudo-random integer between 0 and RAND_MAX.
        snprintf(books[i]->title, MAX_BOOK_TITLE_LENGTH, available_books[i].title, i+1);
        snprintf(books[i]->authors, MAX_BOOK_AUTHORS_AMOUNT * MAX_BOOK_AUTHOR_NAME_LENGTH, "%s", available_books[i].authors);
        snprintf(books[i]->tags, MAX_BOOK_TAGS_AMOUNT * MAX_BOOK_TAG_LENGTH, "%s", available_books[i].tags);
        snprintf(books[i]->annotation, MAX_BOOK_ANNOTATION_LENGTH, "%s", available_books[i].annotation);
    }
    books[length] = NULL;
    return books;
}

int get_length_book(struct book **books) {
    for(int i = 0; ; i++) {
        if (books[i] == NULL) return i+1;
    }
}

void free_books(struct book **books, const int count_book) {
    for (int i = 0; i < count_book; i++) {
        if(books[i]) free(books[i]);
    }
    free(books);
}
