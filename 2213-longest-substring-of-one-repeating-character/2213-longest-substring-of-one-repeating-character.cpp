class Solution {
private:
    struct Node {
        char baayaAkshar;
        char daayaAkshar;
        int lambai;
        int aarambh;
        int ant;
        int sarvottam;
    };

    vector<Node> ped;

    Node jodGanth(const Node& baaya, const Node& daaya) {
        Node parinaam;

        parinaam.baayaAkshar = baaya.baayaAkshar;
        parinaam.daayaAkshar = daaya.daayaAkshar;
        parinaam.lambai = baaya.lambai + daaya.lambai;

        parinaam.aarambh = baaya.aarambh;

        if (
            baaya.daayaAkshar == daaya.baayaAkshar &&
            baaya.aarambh == baaya.lambai
           
        ) {
            parinaam.aarambh = baaya.lambai + daaya.aarambh;
        }

        parinaam.ant = daaya.ant;

        if (
            baaya.daayaAkshar == daaya.baayaAkshar &&
            daaya.ant == daaya.lambai
        ) {
            parinaam.ant = daaya.lambai + baaya.ant;
        }

        parinaam.sarvottam = max(baaya.sarvottam, daaya.sarvottam);

        if (baaya.daayaAkshar == daaya.baayaAkshar) {
            parinaam.sarvottam = max(
                parinaam.sarvottam,
                baaya.ant + daaya.aarambh
            );
        }

        return parinaam;
    }

    void banao(
        int ganth,
        int shuru,
        int samaapt,
        const string& vaakya
    ) {
        if (shuru == samaapt) {
            ped[ganth] = {
                vaakya[shuru],
                vaakya[shuru],
                1,
                1,
                1,
                1
            };
            return;
        }

        int beech = (shuru + samaapt) / 2;

        banao(ganth * 2, shuru, beech, vaakya);
        banao(ganth * 2 + 1, beech + 1, samaapt, vaakya);

        ped[ganth] = jodGanth(
            ped[ganth * 2],
            ped[ganth * 2 + 1]
        );
    }

    void badlo(
        int ganth,
        int shuru,
        int samaapt,
        int sthaan,
        char akshar
    ) {
        if (shuru == samaapt) {
            ped[ganth] = {
                akshar,
                akshar,
                1,
                1,
                1,
                1
            };
            return;
        }

        int beech = (shuru + samaapt) / 2;

        if (sthaan <= beech) {
            badlo(
                ganth * 2,
                shuru,
                beech,
                sthaan,
                akshar
            );
        } else {
            badlo(
                ganth * 2 + 1,
                beech + 1,
                samaapt,
                sthaan,
                akshar
            );
        }

        ped[ganth] = jodGanth(
            ped[ganth * 2],
            ped[ganth * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating(
        string vaakya,
        string badlaavAkshar,
        vector<int>& badlaavSthaan
    ) {
        int kul = vaakya.size();

        ped.resize(4 * kul);

        banao(1, 0, kul - 1, vaakya);

        vector<int> uttar;

        for (int i = 0; i < badlaavSthaan.size(); i++) {
            badlo(
                1,
                0,
                kul - 1,
                badlaavSthaan[i],
                badlaavAkshar[i]
            );

            uttar.push_back(ped[1].sarvottam);
        }

        return uttar;
    }
};
