
struct TreeNode {
    char data;
    std::vector<std::optional <TreeNode*>> children{26, nullptr}; //one node per char
    bool endOfWord; 
};

class PrefixTree {
    TreeNode* root;
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        
        TreeNode* curr_ch = root;
        for (char ch : word){
            int index = ch - 97;
            cout << "INDEX " << index << " FOR CHAR " << ch << " \n";
            if (curr_ch->children[index] == nullptr){
                TreeNode* temp = new TreeNode();
                temp->data = ch;
                curr_ch->children[index] = temp;
            }
            std::optional<TreeNode*> child_opt =curr_ch->children[index];
            curr_ch = * child_opt;
        }

        curr_ch->endOfWord = true;
        cout << "END OF WORD DECLARED AT NODE FOR " << curr_ch->data << " \n" << endl;
    }
    
    bool search(string word) {

        TreeNode* curr_ch = root;
        for (char ch : word){
        
            int index = ch - 97;
            if (curr_ch->children[index] == nullptr){
                return false;
            }

            std::optional<TreeNode*> child_opt =curr_ch->children[index];
            curr_ch = *child_opt;
        
        }

        cout << "WORD " << word << " has bool " << curr_ch->endOfWord << endl;
        return curr_ch->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr_ch = root;
        for (char ch : prefix){
        
            int index = ch - 97;
            if (curr_ch->children[index] == nullptr){
                cout << "PREFIX " << prefix << " has bool " << false << endl;
                return false;
                
            }

            std::optional<TreeNode*> child_opt =curr_ch->children[index];
            curr_ch = *child_opt;
        
        }

        cout << "PREFIX " << prefix << " has bool " << true << endl;
        return true;
    }
};
