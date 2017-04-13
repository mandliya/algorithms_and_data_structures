/**
 * Huffman Encoding:
 * Huffman coding compresses data by using fewer bits to encode more frequently
 * occurring characters so that not all characters are encoded with 8 bits.
 * It is a way to assign binary codes to symbols that reduces the overall number of bits
 * used to encode a typical string of those symbols. 
 * For example, if you use letters as symbols and have details of the frequency of occurrence
 * of those letters in typical strings, then you could just encode each letter with a fixed number of bits,
 * such as in ASCII codes. You can do better than this by encoding more frequently occurring letters such as e and a,
 * with smaller bit strings; and less frequently occurring letters such as q and x with longer bit strings.
 * More details: https://www.cs.duke.edu/csed/poop/huff/info/
 */

#include <iostream>
#include <queue>
#include <vector>

struct HeapNode
{
    char data;
    unsigned int frequency;
    HeapNode *left;
    HeapNode *right;

    HeapNode(char d, unsigned int fr)
    : data {d},
      frequency {fr},
      left {nullptr},
      right {nullptr}
    {}
};

// We need a comparator for comparing two nodes.
struct compare
{
    bool operator() (HeapNode* node1, HeapNode* node2)
    {
        return (node1->frequency > node2->frequency);
    }
};

void generateHuffmanCodeUtil(HeapNode* root, std::string str)
{
    if (!root)
        return;
    
    if (root->data != '$')
    {
        std::cout << root->data << " : " << str << std::endl;
    }

    generateHuffmanCodeUtil(root->left, str + '0');
    generateHuffmanCodeUtil(root->right, str + '1');
}

void generateHuffmanCode(std::string data, std::vector<int> frequencies)
{
    HeapNode *left, *right, *top;

    // Create a minimum heap based on frequency and inserts all characters in it.
    //
    std::priority_queue<HeapNode*, std::vector<HeapNode*>, compare> minHeap;
    unsigned int size = frequencies.size();
    for (unsigned int i = 0; i < size; ++i)
    {
        minHeap.push(new HeapNode(data[i], frequencies[i]));
    }

    while (minHeap.size() != 1)
    {
        // Get two minimum nodes from heap.
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Combine the above two nodes (their frequecies) to generate a
        // new node.Make these two nodes as left and right children of this new node. 
        // Add this node to the min heap, also assign in '$' as data. (character for internal nodes)
        //
        top = new HeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    // We are done generating the tree, lets print it.
    //
    generateHuffmanCodeUtil(minHeap.top(), "");
}

int main()
{
    std::string data{"abcdef"};
    std::vector<int> frequencies = { 5, 9, 12, 13, 16, 45 };

    generateHuffmanCode(data, frequencies);
    return 0;
}