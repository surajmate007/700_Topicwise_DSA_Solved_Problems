class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end());
		vector<vector<int>> stack;
		for(int i=0;i<intervals.size();i++){
			if(stack.empty()){
				stack.push_back(intervals[i]);
				continue;
			}

			if(stack.size()>=1 && intervals[i][0]<=stack.back()[0]){
				int rec=0;
				rec=max(rec,stack.back()[1]);
				while(stack.size()>=1 && intervals[i][0]<=stack.back()[0]){
					stack.pop_back();
			}
					stack.push_back({intervals[i][0],max(rec,intervals[i][1])});
			}
			else if(stack.size()>=1 && intervals[i][0]<=stack.back()[1]){
					int tem=stack.back()[0];
					int tem2=stack.back()[1];
					stack.pop_back();
					stack.push_back({tem,max(intervals[i][1],tem2)});
			}
			else{
					stack.push_back(intervals[i]);
			}
		}
		return stack;

	}
};
