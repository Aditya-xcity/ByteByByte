class Solution {
    struct Server {
        long long kabKhali;
        int wazan, number;

        auto operator<=>(const Server&) const = default;
    };

    using ChotiHeap = priority_queue<Server, vector<Server>, greater<>>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<Server> sabLog;

        for (int bhai = 0; bhai < ssize(servers); ++bhai)
            sabLog.push_back({0, servers[bhai], bhai});

        ChotiHeap khaali(greater<>{}, std::move(sabLog));
        ChotiHeap kaamPe;

        vector<int> jawab;

        for (int samay = 0; samay < ssize(tasks); ++samay) {
            while (!kaamPe.empty() && kaamPe.top().kabKhali <= samay) {
                auto [kab, bhaar, id] = kaamPe.top();
                kaamPe.pop();
                khaali.push({0, bhaar, id});
            }

            ChotiHeap& kahanSe = khaali.empty() ? kaamPe : khaali;

            auto [kab, bhaar, id] = kahanSe.top();
            kahanSe.pop();

            kaamPe.push({
                max<long long>(kab, samay) + tasks[samay],
                bhaar,
                id
            });

            jawab.push_back(id);
        }

        return jawab;
    }
};