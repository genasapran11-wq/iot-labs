import machine, time, gc

led = machine.Pin(15, machine.Pin.OUT)   # світлодіод із шаблону Wokwi
gc.collect()
start = time.ticks_ms()
i = 0

while True:
    led.value(not led.value())
    print("iteration", i, "time", time.ticks_diff(time.ticks_ms(), start),
          "ms, free heap", gc.mem_free(), "B")
    i += 1
    time.sleep_ms(2000)