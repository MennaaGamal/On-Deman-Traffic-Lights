# On-Demand-Traffic-Lights

The system can detect when the button is pressed. Afterwards, based on current state it would decide what to do. It allows pedestrians to walk by making sure cars are stopped first.

In normal mode:
1.	Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
2.	The Yellow LED will blink for five seconds before moving to Green or Red LEDs.

In pedestrian mode:
1.	Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2.	If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3.	If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4.	At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
5.	After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
6.	Traffic lights signals are going to the normal mode again.
