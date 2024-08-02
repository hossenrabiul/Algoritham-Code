class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans,
             int startColor, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        ans[row][col] = newColor;

        int delRow[4] = {-1, 1, 0, 0};
        int delCol[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == startColor && ans[newRow][newCol] != newColor)
                {
                    ans[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;

        int startColor = image[sr][sc];

        bfs(sr, sc, image, ans, startColor, color);

        return ans;
    }
};