# CUB3D by phperrot 🕺
## PRESENTATION

This project aims at reproducing a basic FPS game by using the raycasting method.

## WANNA PLAY? 💥
### Installation

first, copy paste the following code on your terminal:

```shell

cd ~ && cd Downloads && git clone https://github.com/phperrot/cub3d.git cub3d && cd cub3d && chmod 777 Cub3D_bonus && chmod 777 Cub3D && ./Cub3D_bonus maps/master_map.cub

```
this should open a new window:
![Image of Cub3D](https://github.com/phperrot/cub3d/blob/master/items/screen.png)

### Commands

| KEY           | Action        |
| ------------- |:-------------:|
| `ESC`         | exit game     |
| `SPACE BAR`   | shoot         |
| `A`           | move left     |
| `D`           | move right    |
| `W`           | move forward  |
| `S`           | move backward |
| `→`           | turn right    |
| `←`           | turn left     |
| `M`           | hide/display map|
| `O`           | open/close door|
| `P`           | open/close secret door|
| `option`      | change weapon |
| `F10`         | sound on/off |


### Rules

Collect treasures to unlock new levels !

### Modifications 👨‍🎨
You can now create your own map by following this norm:
| Object         | Code          |
| -------------  |:-------------:|
| `1`            | wall          |
| `0`            | floor         |
| `2`            | sprite #1     |
| `3`            | sprite #2     |
| `N`/`E`/`W`/`S`| player initial position + orientation|
| `A`            | ammo          |
| `B`            | bonus         |
| `O`            | ennemy        |
| `T`            | treasure      |
| `D`            | door          |
| `P`            | secret door   |

You can have a look at the [subject](https://github.com/phperrot/cub3d/blob/master/fr.subject.pdf) for further details on how `.cub` files work.
⚠️ Be careful ! All your paths must be valid and your map must be closed (but not necessarily a square 😉)

## WANNA CODE?  👨‍💻

Some useful links can be found in the [documentation file](https://github.com/phperrot/cub3d/blob/master/DOCUMENTATION.md)

