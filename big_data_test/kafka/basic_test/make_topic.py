from kafka.admin import KafkaAdminClient, NewTopic

# Kafka Admin Client 생성
admin_client = KafkaAdminClient(
    bootstrap_servers="localhost:9092",  # Kafka 서버 주소
    client_id='test-admin'
)

# 새 토픽 생성
topic_list = [
    NewTopic(name="test-topic", num_partitions=1, replication_factor=1)
]
admin_client.create_topics(new_topics=topic_list, validate_only=False)

print("토픽이 성공적으로 생성되었습니다!")