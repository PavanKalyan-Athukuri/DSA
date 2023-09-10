class WordDictionary {
    boolean isLast;
    WordDictionary child[];
    public WordDictionary() {
        this.isLast = false;
        this.child = new WordDictionary[26];
    }
    WordDictionary root;
    public void addWord(String word) {
        if(root==null)
        root = new WordDictionary();
        WordDictionary temp = root;
        for(int i=0;i<word.length();i++){
            if(temp.child[word.charAt(i)-'a']==null)
            temp.child[word.charAt(i)-'a'] = new WordDictionary();
            temp = temp.child[word.charAt(i)-'a'];
        }
        temp.isLast = true;
    }
    
    public boolean search(String word) {
        return helper(word,0,root);
    }
    public boolean helper(String word,int index,WordDictionary temp){
        if(index>=word.length())
        return temp.isLast;
        if(temp==null)
        return false;
        if(word.charAt(index)!='.'){
            if(temp.child[word.charAt(index)-'a']!=null){
                return helper(word,index+1,temp.child[word.charAt(index)-'a']);
            }
            else return false;
        }
        else{
            boolean var = false;
            for(int i=0;i<26;i++){
                if(temp.child[i]!=null){
                    var = var|| helper(word,index+1,temp.child[i]);
                }
            }
            return var;
        }
       // return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */