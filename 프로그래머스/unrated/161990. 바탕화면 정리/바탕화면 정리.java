class Solution {
    public int[] solution(String[] wallpaper) {
        int[] answer = {};
        int x1 = Integer.MAX_VALUE, y1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE, y2 = Integer.MIN_VALUE;
        
        for(int i=0;i<wallpaper.length;i++){
            for(int j=0;j<wallpaper[i].length();j++){
                if(wallpaper[i].charAt(j) == '#'){
                    x1 = Math.min(x1, j);
                    y1 = Math.min(y1, i);
                    x2 = Math.max(x2, j);
                    y2 = Math.max(y1, i);
                }
                    
            }
        }
        return new int[]{y1,x1,y2+1,x2+1};
    }
}