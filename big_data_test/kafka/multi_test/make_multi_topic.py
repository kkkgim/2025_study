from kafka.admin import KafkaAdminClient, NewTopic

# Kafka Admin Client 생성
admin_client = KafkaAdminClient(
    bootstrap_servers="localhost:9092",  # Kafka 서버 주소
    client_id='test-admin'
)

# 새 토픽 생성
topic_list = [
    NewTopic(name="multi_topic_1", num_partitions=3, replication_factor=3),
    NewTopic(name="multi_topic_2", num_partitions=2, replication_factor=2)
]
admin_client.create_topics(new_topics=topic_list, validate_only=False)

print("토픽이 성공적으로 생성되었습니다!")