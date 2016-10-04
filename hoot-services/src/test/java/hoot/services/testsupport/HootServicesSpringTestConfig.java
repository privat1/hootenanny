package hoot.services.testsupport;

import javax.sql.DataSource;

import org.apache.commons.dbcp.BasicDataSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.DependsOn;
import org.springframework.context.annotation.FilterType;
import org.springframework.context.annotation.Profile;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import hoot.services.ApplicationContextUtils;
import hoot.services.HootServicesSpringConfig;
import hoot.services.controllers.info.NativeInterfaceStubImpl;
import hoot.services.nativeinterfaces.NativeInterface;


@Configuration
@EnableTransactionManagement
@ComponentScan(basePackages = {"hoot.services"},
        excludeFilters = @ComponentScan.Filter(value = HootServicesSpringConfig.class, type = FilterType.ASSIGNABLE_TYPE))
@Profile("test")
public class HootServicesSpringTestConfig {

    @Bean
    public ApplicationContextUtils applicationContextUtils() {
        return new ApplicationContextUtils();
    }

    @Bean(name = "dataSource")
    public DataSource dataSource() {
        BasicDataSource dataSource = new BasicDataSource();
        dataSource.setDriverClassName("org.postgresql.Driver");
        dataSource.setUrl("jdbc:postgresql://localhost:5432/hoot");
        dataSource.setUsername("hoot");
        dataSource.setPassword("hoottest");
        dataSource.setInitialSize(5);
        dataSource.setMaxActive(10);
        dataSource.setMaxIdle(2);
        dataSource.setDefaultAutoCommit(false);
        dataSource.setRemoveAbandoned(true);
        dataSource.setLogAbandoned(true);
        return dataSource;
    }

    @Bean(name = "transactionManager")
    @Autowired
    @DependsOn("dataSource")
    public PlatformTransactionManager transactionManager(DataSource dataSource) {
        return new DataSourceTransactionManager(dataSource);
    }

    @Bean
    public NativeInterface nativeInterface() {
        return new NativeInterfaceStubImpl();
    }
}