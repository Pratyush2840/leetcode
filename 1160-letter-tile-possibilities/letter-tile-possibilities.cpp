class Solution {
public:
    set<string> st;

    void backtrack(string& tiles, int i) {
        if (i == tiles.size()) {
            return;
        }

        for (int j = i; j < tiles.size(); j++) {
            swap(tiles[i], tiles[j]);

            string s = tiles.substr(0, i + 1);
            st.insert(s);

            backtrack(tiles, i + 1);

            swap(tiles[i], tiles[j]);
        }
    }

    int numTilePossibilities(string tiles) {
        st.clear();
        backtrack(tiles, 0);
        return st.size();
    }
};