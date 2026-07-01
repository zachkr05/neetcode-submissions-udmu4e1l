class MedianFinder {
public:
    vector<double> _arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        //binary search to place the integer
        if (_arr.size() == 0){
            _arr.push_back(num);
            return;
        } 

        //binary search
        int l = 0;
        int r = _arr.size()-1;

        int insert_pos=-1;
        while(l<=r){
            //calc mid num
            int mid = l + (r - l) / 2;
            int mid_num = _arr[mid];

            if (mid_num==num){ //check right half
                insert_pos = mid;
                //insert_pos = mid;
                break;

            } else if (mid_num<num) { //check left half
                // 1 1 3 4 5     2
                l = mid+1;
                //insert_pos = mid;
                continue;
            } else{
                // position
                r = mid-1;
                continue;
            }
        }

        if (insert_pos == -1){
            insert_pos = l;
        }

        _arr.insert(_arr.begin()+insert_pos, num);
    }
    
    double findMedian() {

        if (_arr.size() == 1){
            return _arr[0];
        }

        double middle = (_arr.size()/2.0) - 0.5;
        int is_even = _arr.size() % 2;
        cout << "is_even: "<< is_even<<endl;
        cout << "mid: " << middle<<endl;

        if(is_even != 0){
            //cout << "in if statement "; 
            return _arr[middle];
        }

        int mid_right = ceil(middle);
        int mid_left = floor(middle);

        middle = _arr[mid_right] + _arr[mid_left];

        return middle/2;

    }
};
