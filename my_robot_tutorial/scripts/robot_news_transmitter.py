#!/usr/bin/env python3

import rospy

from std_msgs.msg import String # String is the data type

if __name__ == '__main__' :

    rospy.init_node('robot_news_radio_transmitter') # initiate node

    pub = rospy.Publisher('/robot_news_radio',String,queue_size = 10) #setup the publisher with the topic name, datatype, queue_size

    rate = rospy.Rate(2)# define the rate at which we are going to publish data

    while not rospy.is_shutdown(): #while the node is running  
        
        msg = String() #msg is an object of string
        
        msg.data="Hi,this is hari from the robot news radio !" #store the message in msg
        
        pub.publish(msg) # publish the data
        
        rate.sleep() # runs the code at 2Hz

    rospy.loginfo("Node was stopped")
