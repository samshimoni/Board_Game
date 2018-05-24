#include "Player.h"

class Champion : public Player
{
    public:

        const string name() const override { return "Shmuel Shimoni"; }
        const Coordinate play(const Board& board) override;
};