    vector<int> node_depths;
public:
    void maxDepth1(Node*root, int depth){
        int sz = 0;
        if(root != nullptr){
            sz = root->children.size();
        }
        if(sz > 0){
            for(int i = 0; i < sz; ++i){
                if(root->children[i]->children.size() > 0){
                    maxDepth1(root->children[i],depth + 1);
                }
                else{
                    node_depths.push_back(depth + 1);
                }
            }
        }
    }
    
    int maxDepth(Node* root) {
        if(root != nullptr){
            if(root->children.size() == 0){
                return 1;
            }
        }
        maxDepth1(root,1);
        int max = 0;
        for(int i = 0; i < node_depths.size(); ++i){
            if(max < node_depths[i]){
                max = node_depths[i];
            }
        }
        return max;
    }
};