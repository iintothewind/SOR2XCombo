#include "data/scripts/assets.h"

void main() {
  playSound();
}

void playSound() {
  playsample(SAMPLE_MONEY, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
}