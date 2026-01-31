class Twitter {
  private:
  int time;
  unordered_map<int,vector<pair<int,int>>>tweets;
  unordered_map<int,unordered_set<int>>following;

public:
    Twitter() {
     time=0;   
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
     priority_queue<pair<int,int>>pq;

        for(auto& it:tweets[userId]){
            pq.push(it);
        }


        for(auto& it:following[userId]){
          for(auto& t:tweets[it]){
              pq.push(t);
          }
        }

        while(!pq.empty() && feed.size()<10){
          feed.push_back(pq.top().second);
          pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)return ;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
          following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */