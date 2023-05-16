//
//    // if cowboy is alive and has cartridge, shoot the opponent with 10 points and one bullet is out of cartridge, else the enemy wont harm
//    void Cowboy::shoot(ariel::Character *opponent)
//    {
//        // check if opponent is dead then throw exception
//        if (!opponent->isAlive())
//        {
//            throw std::runtime_error("cant kill dead opponent");
//        }
//        //if cowboy is dead throw exception
//        if (!this->isAlive())
//        {
//            throw std::runtime_error("dead attacker cant attack");
//        }
//        // check if opponent is not the cowboy iteself
//        if(this == opponent)
//        {
//            throw std::runtime_error("cowboy cant shoot itself, is not suicidal");
//        }
//        // check if cowboy is alive
//        if(this->isAlive())
//        {
//            // check if cartridge is not empty
//            if(this->hasboolets())
//            {
//                opponent->hit(10); // shoot the opponent with 10 points
//                --this->cartridge_;
//            }
//        }
//    }
//    // overrides the print function from character do the same hust add info that the character is cowboy
//    string Cowboy::print() const
//    {
//
//        string info = "C: ";
//        info += Character::print();
//        return info;
//    }
//}