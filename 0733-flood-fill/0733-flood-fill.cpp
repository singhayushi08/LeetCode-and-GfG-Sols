class Solution {
    void dfs(int i, int j, vector<vector<int>>& image, int starting_pixel_color, int color, vector<vector<int>>& vis, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n) return; // out of bound
        if(image[i][j] != starting_pixel_color) return; 
        if(vis[i][j] == 1) return;
        
        vis[i][j] = 1;
        image[i][j] = color;
        
        // now call dfs on 4 directions
        dfs(i-1, j, image, starting_pixel_color, color, vis, m, n);
        dfs(i, j+1, image, starting_pixel_color, color, vis, m, n);
        dfs(i+1, j, image, starting_pixel_color, color, vis, m, n);
        dfs(i, j-1, image, starting_pixel_color, color, vis, m, n);
        
        return;
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int starting_pixel_color = image[sr][sc];
        dfs(sr, sc, image,  starting_pixel_color, color, vis, m, n);
        return image;
    }
};