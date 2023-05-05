/* Queue
 *
 * Description
 *
 * Program has a cycle that tells how many cars can go through the green light
 * untill it turns red. If traffic light is red cars can be added in the queue
 * to wait for their turn. Cars can be removed from the queue only by turning
 * the light green. Traffic light colours can be changed from green to red or
 * red to green. Yellow isn't added because it does nothing. If light's colour
 * turns to green from red the cycle's amount of cars can go trough and then the
 * light turns back to red. Program prints the register numbers of the cars that
 * got through the green light. Program also prints the register numbers of the
 * cars that are waiting in the red light or if the line is empty, program
 * informs that. If the light is green and car is added, the car can go
 * immediately through the light.
 *
 * Writer of the program
 *
 * Name: EILeh
 */


#ifndef QUEUE_HH
#define QUEUE_HH

#include <string>

using namespace std;

class Queue
{
public:
    // Constructor that initializes the attribute cycle_.
    // (The other attibutes are initialized in the private part below.)
    Queue(unsigned int cycle);

    // Destructor that deletes all the remaining vehicles from the queue.
    ~Queue();

    // If the color of traffic light is red, inserts a vehicle, the register
    // number of which is reg, to the queue.
    void enqueue(string const& reg);

    // Switches the color of traffic light from green to red or vice versa.
    // If the new color is green, lets at least <cycle_> vehicles
    // go on (i.e. calls dequeue at least <cycle_> times), and finally
    // resets the color to red again.
    void switch_light();

    // Resets the attribute cycle_.
    void reset_cycle(unsigned int cycle);

    // Prints the color of traffic light and the register numbers of those
    // cars that are waiting in the traffic light queue (if any).
    void print() /*const*/;


private:
    // A single vehicle, i.e. queue element
    struct Vehicle {
        string reg_num;
        Vehicle* next;
    };

    // Pointer to the first vehicle in the traffic light queue
    Vehicle* first_ = nullptr;

    // Pointer to the last vehicle in the traffic light queue
    Vehicle* last_ = nullptr;

    // Tells if the color of the traffic light is green or not
    bool is_green_ = false;

    // The number of vehicles that can pass the traffic lights during
    // the same green period
    unsigned int cycle_;

    // You can define more private features here

    bool dequeue(string &reg);

};

#endif // QUEUE_HH
