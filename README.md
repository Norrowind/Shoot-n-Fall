# Side-scroller shooter game on UE4 with C++ and some Blueprints(properties settings).

# [Video with current state of game](https://drive.google.com/file/d/1frUIURwaEy13ws4otfLFwBIXVvKnus4X/view?usp=drivesdk)
*Video will be updated as soon as new feature will be realized.*
**Last update: 08.11.19**

## Main goal is to push-off enemy from the platform to "abyss" using weapons. Game level is the set of platforms in the air. Platforms are generated randomly( position and size).

### States of game:
- Ready:
  - Basic movement and animations
  - Shooting system with ability to make automatic weapon(can set rate of fire)
  - Random level generation(logic imlemented in PlatformBuilder class)

- Will be imlemented in the nearest future(untill the end of November):
  - AI logic, using BT
  - Multiplayer support, using UE4 replication system
  - Power-ups and different weapons(assault rifle, shotgun, rocket launcher, sniper rifle, sword)
  - UI, using UE 4 UMG system

### Assets used:
- Character and animations: https://www.mixamo.com
- Weapons: https://www.unrealengine.com/marketplace/en-US/slug/sci-fi-weapons-dark
