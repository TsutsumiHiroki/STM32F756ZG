#include <Arduino.h>
#include <TaskManager.h>
#include <Input.hpp>
#include <Output.hpp>
#include <MsgPacketizer.h>

namespace led
{
  Output red(74);
  Output blue(73);
  Output green(PIN_A23);
} // namespace led
namespace button
{
  Input user(75, false);
} // namespace button

namespace control
{
  void setCristmasTreeStart();
  void setCristmasTreeStop();
}

namespace communication
{
  void onControlSyncRecieved(uint8_t state);
  void dataSender();

  int byte = 0;
}

void setup()
{
  Serial3.begin(115200);

  Tasks.add([]
            {
              uint8_t state = 0b00000001;
              communication::onControlSyncRecieved(state); })
      ->startFps(50);
  Tasks.add(&communication::dataSender)->startFps(10);

  control::setCristmasTreeStart();

  Tasks.add(&control::setCristmasTreeStop)
      ->startOnceAfterSec(3.0);
}

void loop()
{
  Tasks.update();
}

void control::setCristmasTreeStart()
{
  led::blue.on();
  led::red.on();
  led::green.on();
}

void control::setCristmasTreeStop()
{
  led::blue.off();
  led::red.off();
  led::green.off();
}

void communication::onControlSyncRecieved(uint8_t state)
{
  led::green.set(state & (1 << 0)); // CHECK
  led::blue.set(state & (1 << 1));  // DUMP
  led::red.set(state & (1 << 2));   // CLOSE
  if (state & (1 << 0))
  {
    led::blue.on();
  }
  if (state & (1 << 0) && state & (1 << 2))
  {
    led::blue.off();
  }
}

void communication::dataSender()
{
  if (Serial3.available() > 0)
  {
    communication::byte = Serial3.read();
    if (communication::byte == 3)
    {
      Serial3.print("Hello STM32duino");
    }
  }
}
