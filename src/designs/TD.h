

#ifndef H_TOURNAMENT_DESIGN
#define H_TOURNAMENT_DESIGN


class TournamentDesign
{

    public:
        TournamentDesign(int n);
        ~TournamentDesign();

        virtual bool validate_design(TournamentDesign design);

    private:
        int n;
        int n_courts;
        int n_rounds;
        int n_teams;

};




#endif // !H_TOURNAMENT_DESIGN