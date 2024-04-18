#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
typedef struct Trie
{	
	int wordCounter;
	struct Trie* next[26];
	
} trie;

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{
	int len = strlen(word);
	trie* temp = pTrie;
	for (int x = 0; x <= len; x++) {
		
		// if its the end of the word, add to the word counter.
		if (x == len) 
			temp->wordCounter += 1;
		// or else jump to the next trie
		else 
			// if the trie hasnt yet been created.
			if (temp->next[word[x] - 'a'] == NULL)
				temp->next[word[x] - 'a'] = createTrie();
			temp = temp->next[word[x] - 'a'];
	}
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
}

// deallocate the trie structure
struct Trie* deallocateTrie(struct Trie *pTrie)
{
	if (pTrie == NULL)
		return NULL;
	for (int z = 0; z < 26; z++)
		deallocateTrie(pTrie->next[z]);
	free(pTrie);
	return NULL;
}

// Initializes a trie structure
struct Trie *createTrie()
{
	trie* res = (trie*)malloc(sizeof(trie));
	res->wordCounter = 0;
	for (int y = 0; y < 26; y++)
		res->next[y] = NULL;
	return res;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}