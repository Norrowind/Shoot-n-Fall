# Side-scroller shooter game . The game is being created on UE4 with C++ and some Blueprints(properties settings).

# [Video which shows basic gameplay(early prototype)](https://drive.google.com/open?id=1_vpVHC_RWn7xk4VV_mTR1R6L21WRFba4)
*Video will be updated as soon as new feature will be realized.*
# [Video which shows custom AI pathfinding logic, based on A* algorithm](https://drive.google.com/file/d/1dzZz3mio-nONtEC_kmLxKLNWgk7YP9ZT/view?usp=drivesdk)

## Main goal is to push-off enemy from the platform to "abyss" using weapons. Game level is the set of platforms in the air. Platforms are generated randomly( position and size).



### State of game:
- Ready:
  - Basic movement and animations
  - Shooting system with ability to make automatic weapon(can set rate of fire)
  - Random level generation(logic imlemented in PlatformBuilder class)
  - AI logic

- Will be imlemented in the nearest future(untill the end of November):
  - Multiplayer support, using UE4 replication system
  - Power-ups and different weapons(assault rifle, shotgun, rocket launcher, sniper rifle, sword)
  - UI, using UE 4 UMG system

### Assets used:
- Character and animations: https://www.mixamo.com
- Weapons: https://www.unrealengine.com/marketplace/en-US/slug/sci-fi-weapons-dark
