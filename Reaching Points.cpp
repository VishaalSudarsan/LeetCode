class Solution {
public:
    
    bool reachingPointsInner(int& sx, int& sy, int& tx, int& ty)
    {
        if(sx == tx && sy == ty)
            return true;
        else if(tx < sx || ty < sy)
        {
            if(tx==0) tx +=ty;
            if(ty==0) ty +=tx;
            
            if(((tx-sx)%ty == 0 && sy == ty) || (sx == tx && (ty-sy)%tx == 0))
                return true;
            else 
                return false;
        }
        else
        {
            if(ty > tx)
            {
                ty = ty%tx;
                return reachingPointsInner(sx, sy, tx, ty);
            }
            else if(ty < tx)
            {
                tx = tx%ty;
                return reachingPointsInner(sx, sy, tx, ty);
            }
            else
                return false;
        }
    }
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx < sx || ty < sy) return false;
        return reachingPointsInner(sx, sy, tx, ty );
    }
};
