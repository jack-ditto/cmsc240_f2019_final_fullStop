#ifndef __GAME_H__
#define __GAME_H__

#include "string"

class Game
{
   private:
      int totalTime;
   
   public: 

      // Constructors
      Game();
      Game(std::string filePath);

      // Initial run method
      void run();

      void moveTraffic();
};
#endif
