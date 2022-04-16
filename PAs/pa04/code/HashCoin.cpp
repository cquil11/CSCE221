#include "Block.h"
#include "Hash.h"

#include <iostream>
#include <string>

/**
 * @brief While the function has yet to produce a valid nonce, the loop continues
 *  and adds on a new character (between ASCII values 48 and 122) to the nonce string
 * 
 * @param b current Block object begin evaluated
 */
void mine(Block &b)
{
    bool foundValidNonce = false;
    unsigned ascii = 48;
    unsigned i = 0;
    std::string nonce = "";
    while (!foundValidNonce)
    {
        char c = ascii;
        nonce += c;
        foundValidNonce = b.sign_block(nonce);
        i++;
        ascii = 48 + (i % 75);
    }
}

int main()
{
    std::string current;
    Block *prev = nullptr;
    Block *cur = nullptr;

    // Keeps accepting user input until they enter a blank line
    while (true)
    {
        std::string transaction;
        std::getline(std::cin, transaction);

        if (!transaction.empty())
        {
            cur = new Block(transaction, prev);
            mine(*cur);
            prev = cur;
        }
        else
            break;
    }
    // After the user finishes entering transactions, program loops through
    // all transactions starting at the most recent one and prints them out in reverse order
    Block *t = cur;
    while (t)
    {
        std::cout << *t;
        prev = t;
        t = t->get_prev();
    }
    prev = nullptr;
    // Frees all memory allocated on the heap
    while (cur)
    {
        prev = cur->get_prev();
        delete cur;
        cur = prev;
    }

}