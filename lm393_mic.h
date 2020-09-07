#ifndef LM393_MIC_H_
#define LM393_MIC_H_

const int sensitivity = 675;

extern int readMicrophone(int audioPin) {
  if (analogRead(audioPin) < sensitivity) {
    return HIGH;
  } else {
    return LOW;
  }
}

#endif // LM393_MIC_H_
