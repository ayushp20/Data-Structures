#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Thread {
	public:
		int id;
        long long nextFreeTime;
	    Thread (int id) {
            this->id = id;
            nextFreeTime = 0;
        }
};

struct ThreadCompare {
	bool operator()(const Thread &w1, const Thread &w2) const {
		if(w1.nextFreeTime == w2.nextFreeTime)
			return w1.id > w2.id;
		else
            return w1.nextFreeTime > w2.nextFreeTime;
	}
};

class JobQueue {
 private:
  int num_Threads_;
  vector<int> jobs_;

  vector<int> assigned_Threads_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_Threads_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_Threads_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    assigned_Threads_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_Threads_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_Thread = 0;
      for (int j = 0; j < num_Threads_; ++j) {
        if (next_free_time[j] < next_free_time[next_Thread])
          next_Thread = j;
      }
      assigned_Threads_[i] = next_Thread;
      start_times_[i] = next_free_time[next_Thread];
      next_free_time[next_Thread] += duration;
    }
  }

  void FastAssignJobs() {
	assigned_Threads_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
	priority_queue<Thread, vector<Thread>, ThreadCompare> pq;
	for(int i = 0; i < num_Threads_; i++) {
		pq.push(Thread(i));

	}
	for (int i = 0; i < jobs_.size(); i++) {
		Thread freeThread = pq.top();
		pq.pop();
		assigned_Threads_[i] = freeThread.id;
		start_times_[i] = freeThread.nextFreeTime;
		freeThread.nextFreeTime += jobs_[i];
		pq.push(freeThread);
	}
  }

 public:
  void Solve() {
    ReadData();
    // AssignJobs();
	FastAssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
