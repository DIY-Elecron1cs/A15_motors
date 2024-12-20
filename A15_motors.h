#pragma once

#define FW 0
#define BW 1
#define R 2
#define L 3
#define RF 4
#define LF 5
#define RB 6
#define LB 7
#define STOP 8
#define ON 1
#define OFF 0

class A15Motors {
  public:
    A15Motors(uint8_t rf, uint8_t rb, uint8_t lf, uint8_t lb) {
      _rf = rf;
      _rb = rb;
      _lf = lf;
      _lb = lb;
      pinMode(_rf, OUTPUT);
      pinMode(_rb, OUTPUT);
      pinMode(_lf, OUTPUT);
      pinMode(_lb, OUTPUT);
    }

    void setSpeed(uint8_t speed) {
      _speed = speed;
      _constSpeed = speed;
    }

    void manualGo(uint8_t rf1, uint8_t rb1, uint8_t lf1, uint8_t lb1) {
      analogWrite(_rf, rf1);
      analogWrite(_rb, rb1);
      analogWrite(_lf, lf1);
      analogWrite(_lb, lb1);
    }

    void go(uint8_t direction) {
      if (direction == FW)
        manualGo(_speed, 0, _speed, 0);
      if (direction == BW)
        manualGo(0, _speed, 0, _speed);
      if (direction == LF)
        manualGo(_speed, 0, 0, 0);
      if (direction == RF)
        manualGo(0, 0, _speed, 0);
      if (direction == RB)
        manualGo(0, _speed, 0, 0);
      if (direction == RB)
        manualGo(0, 0, 0, _speed);
      if (direction == R)
        manualGo(0, _speed, _speed, 0);
      if (direction == L)
        manualGo(_speed, 0, 0, _speed);
    }

    void brake() {
      manualGo(0, 0, 0, 0);
    }

    void setSmooth(uint8_t smooth) {
      _smooth = smooth;
    }

    void smoothGo(uint8_t directionSmooth) {
      for (_speed = 0; _speed < _constSpeed; _speed++) {
        go(directionSmooth);
        _delMill = millis() + _smooth;
        while (millis() < _delMill) {
        }
      }
    }
    void smoothBrake(uint8_t directionSmooth) {
      for (_speed = _constSpeed; _speed > 0; _speed--) {
        go(directionSmooth);
        _delMill = millis() + _smooth;
        while (millis() < _delMill) {
        }
      }
    }

  private:
    uint16_t _delMill;
    uint8_t _smooth = 8;
    uint8_t _rf;
    uint8_t _rb;
    uint8_t _lf;
    uint8_t _lb;
    uint8_t _speed;
    uint8_t _constSpeed;
};

class A15Motors_PWM {
  public:
    A15Motors_PWM(uint8_t enable, uint8_t rf, uint8_t rb, uint8_t lf, uint8_t lb) {
      _enable = enable;
      _rf = rf;
      _rb = rb;
      _lf = lf;
      _lb = lb;
      pinMode(_enable, OUTPUT);
      pinMode(_rf, OUTPUT);
      pinMode(_rb, OUTPUT);
      pinMode(_lf, OUTPUT);
      pinMode(_lb, OUTPUT);
    }

    void setSmooth(uint8_t smooth) {
      _smooth = smooth;
    }

    void setSpeed(uint8_t speed) {
      _speed = speed;
      _constSpeed = speed;
    }
    void manualGo(bool rf1, bool rb1, bool lf1, bool lb1) {
      digitalWrite(_rf, rf1);
      digitalWrite(_rb, rb1);
      digitalWrite(_lf, lf1);
      digitalWrite(_lb, lb1);
      analogWrite(_enable, _speed);
    }
    void go(uint8_t direction) {
      if (direction == FW)
        manualGo(HIGH, 0, HIGH, 0);
      if (direction == BW)
        manualGo(0, HIGH, 0, HIGH);
      if (direction == LF)
        manualGo(HIGH, 0, 0, 0);
      if (direction == RF)
        manualGo(0, 0, HIGH, 0);
      if (direction == RB)
        manualGo(0, HIGH, 0, 0);
      if (direction == RB)
        manualGo(0, 0, 0, HIGH);
      if (direction == R)
        manualGo(0, HIGH, HIGH, 0);
      if (direction == L)
        manualGo(HIGH, 0, 0, HIGH);
    }
    void brake() {
      manualGo(0, 0, 0, 0);
    }

    void smoothGo(uint8_t directionSmooth) {
      for (_speed = 0; _speed < _constSpeed; _speed++) {
        go(directionSmooth);
        _delMill = millis() + _smooth;
        while (millis() < _delMill) {
        }
      }
    }

    void smoothBrake(uint8_t directionSmooth) {
      for (_speed = _constSpeed; _speed > 0; _speed--) {
        go(directionSmooth);
        _delMill = millis() + _smooth;
        while (millis() < _delMill) {
        }
      }
    }

  private:
    uint16_t _delMill;
    uint8_t _smooth = 8;
    uint8_t _enable;
    uint8_t _rf;
    uint8_t _rb;
    uint8_t _lf;
    uint8_t _lb;
    uint8_t _speed;
    uint8_t _constSpeed;
};
