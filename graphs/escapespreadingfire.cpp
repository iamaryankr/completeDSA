class Solution {
public:
    int delrow[4] = {1,0,-1,0};
    int delcol[4] = {0,1,-0,-1};
    bool isValid(int row, int col, int m, int n){
        if(row<m && row>=0 && col<n && col>=0) return true;
        return false;
    }
    int mintimeTOreach(int timewaste, vector<vector<int>> &grid,
    vector<vector<int>> &dist, vector<vector<int>> &firetime){
        queue<pair<int,int>> q;
        q.push({0,0});
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                dist[i][j] = 1e9;
            }
        }
        dist[0][0] = timewaste;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(!isValid(nrow, ncol, m, n) && grid[nrow][ncol]==2) continue;

                int newmin = min(dist[nrow][ncol], dist[row][col]+1);
                if(nrow==m-1 && ncol==n-1 && newmin<=firetime[nrow][ncol]){
                    return newmin;
                }
                if(newmin >= firetime[nrow][ncol]) continue;
                if(dist[nrow][ncol] > dist[row][col]+1){
                    dist[nrow][ncol] = dist[row][col]+1;
                    q.push({nrow, ncol});
                }
            }
        }
        return 1e9+1;
    }
    int findmaxtime(vector<vector<int>> &grid, int m, int n,
    vector<vector<int>> &firetime, vector<vector<int>> &dist){
        if(firetime[m-1][n-1] == 1e9){
            if(mintimeTOreach(0, grid, dist, firetime) >= 1e9) return -1;
            else return 1e9;
        }
        int low = 0, high = m*n -1;
        int ans = -1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(mintimeTOreach(mid, grid, dist, firetime) <= firetime[m-1][n-1]){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        if(ans >= m*n + 1) return 1e9;
        else return ans;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> firetime(m+1, vector<int> (n+1));
        vector<vector<int>> dist(m+1, vector<int> (n+1));

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                firetime[i][j] = 1e9;
            }
        }
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    firetime[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(isValid(nrow, ncol, m, n) && grid[nrow][ncol]!=2){
                    if(firetime[nrow][ncol] > firetime[row][col] + 1){
                        firetime[nrow][ncol] = firetime[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        int ans = findmaxtime(grid, m, n, firetime, dist);
        return ans;

    }
};
///solnn
class Solution {
public:
    int m, n;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int fire_time[302][302];
    int dis[302][302];

    int minimum_time_to_reach_bottom_right(int waste_time,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        q.push({0,0});
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dis[i][j]=1e9;
            }
        }
        dis[0][0]=waste_time;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]==2){  
                    continue;   
                }
                int new_min=min(dis[nx][ny],dis[x][y]+1);
                if(nx==m-1 && ny==n-1 && new_min<=fire_time[nx][ny]){
                    return new_min;
                } 
                if(new_min>=fire_time[nx][ny]){
                    continue;
                }   
                if(dis[nx][ny]>dis[x][y]+1){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                }             
            }          
        }      
        return 1e9+1;  
    }

    int find_maximum_time(vector<vector<int>>&grid){      
        if(fire_time[m-1][n-1]==1e9){    
            if(minimum_time_to_reach_bottom_right(0,grid)>=1e9){
                return -1;
            }   
            else{
                return 1e9;
            }   
        }
        int low=0,high=(m*n)+1;
        int ans=-1;
        while(low<=high){   
            int mid=(low+high)/2;   
            if(minimum_time_to_reach_bottom_right(mid,grid)<=fire_time[m-1][n-1]){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }    
        }
        if(ans>=(m*n)+1){
            return 1e9;
        }
        else{
            return ans;
        }
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                fire_time[i][j]=1e9;
            }
        }        
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    fire_time[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=2){
                    if(fire_time[nx][ny]>fire_time[x][y]+1){         
                        fire_time[nx][ny]=fire_time[x][y]+1;          
                        q.push({nx,ny});          
                    }      
                }   
            }   
        }
        int ans=find_maximum_time(grid);
        return ans;
    }
};