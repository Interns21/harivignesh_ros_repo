#!usr/bin/env python3

import rospy
from std_msgs.msg import Int64

number_received = Int64()
total = Int64()
def callback_fn(msg):
    number_received.data = msg.data
    total.data = total.data + number_received.data

if __name__ == "__main__":

    rospy.init_node('number_counter')
    sub = rospy.Subscriber('/number',Int64,callback_fn)
    pub = rospy.Publisher('/number_counter',Int64,queue_size = 10)
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():   
        pub.publish(total)
        rate.sleep()

rospy.loginfo("Node was stopped")
