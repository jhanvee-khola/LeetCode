class Solution {
public:
    void ff(vector<vector<int>> &image,int i,int j,int m,int n,int oc,int nc){
        //oc->old color
        //nc->new color
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        
        if(i<0||j<0||i>=m||j>=n){
            return;
        }
        if(image[i][j]!=oc){
            return;
        }
        image[i][j]=nc;
        for(int k=0;k<4;k++){
            ff(image,i+dx[k],j+dy[k],m,n,oc,nc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oc=image[sr][sc];
        if(oc == newColor){
            return image;
        } 
        int m=image.size(),n=image[0].size();
        ff(image,sr,sc,m,n,oc,newColor);
        return image;
    }
};