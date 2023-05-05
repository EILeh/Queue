#include "queue.hh"
#include <iostream>


Queue::Queue(unsigned int cycle):
    first_(nullptr),
    last_(nullptr),
    is_green_(false),
    cycle_(cycle)

{

}


Queue::~Queue()
{
    Vehicle *car = first_;
    Vehicle *temp;

    while ( car != nullptr )
    {
        temp = car;
        car = car->next;
        delete temp;
    }
}


bool Queue::dequeue(string &reg)
{
    if ( first_ == nullptr )
    {
        return false;
    }

    Vehicle *first_car_in_line = first_;

    first_ = first_car_in_line->next;

    reg = first_car_in_line->reg_num;

    delete first_car_in_line;

    return true;

}


void Queue::enqueue(const string &reg)
{

    Vehicle *car = new Vehicle;
    car->reg_num = reg;
    car->next = nullptr;

    if ( (first_ == nullptr) && (is_green_) )
    {
        cout << "GREEN: The vehicle " << car->reg_num << " need not stop to wait" << endl;
        if (dequeue(car->reg_num) == true)
        {

            is_green_ = true;
        }
        return;
    }

    if ( first_ == nullptr )
    {
        first_ = car;
        return;
    }

    if ( last_ != nullptr )
    {
        car->next = last_;
        last_ = car;
        return;
    }

    Vehicle *current = first_;

    while ( current->next != nullptr )
    {
        current = current->next;
    }

    car->next = current->next;
    current->next = car;

}


void Queue::switch_light()
{
    unsigned int index = 0;
    Vehicle *car = first_;
    //Vehicle *temp = first_;


    if ( !is_green_ )
    {

        if ( first_ == nullptr )
        {
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;

            is_green_ = true;

            return;
        }

        else if ( car->next == nullptr )
        {

            cout << "GREEN: Vehicle(s) " << car->reg_num
                 << " can go on" << endl;

            if (dequeue(car->reg_num) == true)
            {
                is_green_ = false;
            }

            return;
        }

        cout << "GREEN: Vehicle(s) ";

        if ( car->next != nullptr )
        {
            while ( (index < cycle_) )
            {
                cout  << car->reg_num << " ";

                if ( dequeue(car->reg_num) == true )
                {
                    car = car->next;

                    index++;
                }

            }

            cout << "can go on" << endl;

            is_green_ = false;

            return;
        }

        is_green_ = true;

    }


    else if ( is_green_ )
    {

        if ( first_ == nullptr )
        {
            cout << "RED: No vehicles waiting in traffic lights" << endl;

            is_green_ = false;

            return;
        }

        else if ( car->next == nullptr )
        {
            cout << "RED: Vehicle(s) ";
            cout  << car->reg_num << " waiting in traffic lights" << endl;

            is_green_ = false;

            return;

        }

        cout << "RED: Vehicle(s) ";

        while ( car != nullptr )
        {
            cout  << car->reg_num << " ";

            car = car->next;

        }

        cout << "waiting in traffic lights" << endl;

        is_green_ = true;

    }

}


void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;

}


void Queue::print()
{

    Vehicle *car = first_;

    if ( first_ != nullptr )
    {
        cout << "RED: Vehicle(s) ";

        while ( car != nullptr )
        {
            cout  << car->reg_num << " ";

            car = car->next;

        }

        cout << "waiting in traffic lights" << endl;

        is_green_ = false;

    }

    else if ( first_ == nullptr )
    {
        if ( !is_green_ )
        {
            cout << "RED: No vehicles waiting in traffic lights" << endl;

            return;

        }

        else
        {
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;

            return;
        }
    }

}


