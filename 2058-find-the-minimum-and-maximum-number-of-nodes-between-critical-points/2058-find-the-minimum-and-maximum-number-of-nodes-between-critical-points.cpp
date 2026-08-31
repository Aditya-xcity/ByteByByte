class Solution { 
public: 
    vector<int> nodesBetweenCriticalPoints(ListNode* head) { 
        int SabseChhota = 100000, Ginti = 1; 
        int Jagah[2] = {0, 0}; 
 
        auto Pehla = head, Beech = head->next, Agla = head->next->next; 
 
        auto Mahatvapurn = [&]() { 
            auto A = Pehla->val, B = Beech->val, C = Agla->val; 
            return (A < B && B > C) || (A > B && B < C); 
        }; 
 
        while (Agla) { 
            if (Mahatvapurn()) { 
                if (Jagah[0]) SabseChhota = min(SabseChhota, Ginti - Jagah[Jagah[1] > 0]); 
                Jagah[Jagah[0] > 0] = Ginti; 
            } 
 
            Pehla = Beech; 
            Beech = Agla; 
            Agla = Agla->next; 
            Ginti++; 
        } 
 
        if (Jagah[1]) return {SabseChhota, Jagah[1] - Jagah[0]}; 
 
        return {-1, -1}; 
    } 
};